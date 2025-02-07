/** 
* @file zz_renderer_d3d.h
* @brief renderer Direct 3D interface.
* @author Jiho Choi (zho@korea.com)
* @version 1.0
* @date    21-feb-2002
*
* $Header: /engine/include/zz_renderer_d3d.h 62    05-12-16 8:11p Choo0219 $
*/

#ifndef __ZZ_RENDERER_D3D_H__
#define __ZZ_RENDERER_D3D_H__

#include <d3d9.h>
#include <d3dx9.h>
#include <vector>

#ifndef __ZZ_RENDERER_H__
#include "zz_renderer.h"
#endif

// d3d<->znzin color conversion
/* from
#define D3DCOLOR_ARGB(a,r,g,b) \
	((D3DCOLOR)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))
*/
#define ZZ_COLOR_RGBA(r, g, b, a) (D3DCOLOR_ARGB((a), (r), (g), (b)))
#define ZZ_TO_D3DRGBA(r, g, b, a) (D3DCOLOR_ARGB(int(255.0f*(a)), int(255.0f*(r)), int(255.0f*(g)), int(255.0f*(b))))
#define ZZ_TO_D3DXRGB(x, y, z) (D3DCOLOR_XRGB(int(255.0f*(x)), int(255.0f*(y)), int(255.0f*(z))))
#define ZZ_FROM_D3DRGBA(r, g, b, a) (vec4(float(r)/255.0f, float(g)/255.0f, float(b)/255.0f, float(a)/255.0f))
#define ZZ_FROM_D3DCOLOR(color) (vec4(float((color>>16)&0xff)/255.0f, float((color>>8)&0xff)/255.0f, float(color&0xff)/255.0f, float((color>>24)&0xff)/255.0f))

// Direct3D renderer interface
class zz_view_d3d;
class zz_texture;

//--------------------------------------------------------------------------------
class zz_renderer_d3d : public zz_renderer {
  //--------------------------------------------------------------------------------
private:
  bool                    _scene_began;
  zz_renderer_cached_info _cached;

  D3DPRESENT_PARAMETERS _parameters; // device parameters
  bool                  _device_lost;

  bool _sprite_began;

  char _sprite_name[ZZ_MAX_STRING]; // current sprite name in begin/end block

  // wrapper for CreateDevice
  HRESULT _create_device(
    UINT                   Adapter,
    D3DDEVTYPE             DeviceType,
    HWND                   hFocusWindow,
    DWORD                  BehaviorFlags,
    D3DPRESENT_PARAMETERS* pPresentationParameters,
    IDirect3DDevice9**     ppReturnedDeviceInterface
  );

protected:
  // direct3d interface pointer
  LPDIRECT3D9 d3d;

  // direct3d device
  LPDIRECT3DDEVICE9 d3d_device;

  // vertex buffers & index buffers
  zz_pool<LPDIRECT3DTEXTURE9>      d3d_textures;
  zz_pool<LPDIRECT3DVERTEXBUFFER9> vertex_buffer_pool;
  zz_pool<LPDIRECT3DINDEXBUFFER9>  index_buffer_pool;

  LPDIRECT3DVERTEXBUFFER9 line_vertex_buffer;
  LPDIRECT3DVERTEXBUFFER9 overlay_vb;
  LPDIRECT3DVERTEXBUFFER9 shadowmap_vb; // shadowmap blur vertex buffer
  LPDIRECT3DVERTEXBUFFER9 glow_vb;      // glow blur vertex buffer
  LPDIRECT3DTEXTURE9      shadowmap_overlay_texture;

  // normal back buffer
  // 	LPDIRECT3DSURFACE9 backbuffer_surface; // real back buffer   //test
  LPDIRECT3DSURFACE9 backbuffer_zsurface;

  // virtual backbuffer (by texture)
  LPDIRECT3DSURFACE9 v_backbuffer_surface;  // rendertarget surface for backbuffer
  LPDIRECT3DSURFACE9 v_backbuffer_zsurface; // rendertarget depth surface for backbuffer
  LPDIRECT3DTEXTURE9 v_backbuffer_texture;  // rendertarget texture for backbuffer

  // for ssao effect
  LPDIRECT3DSURFACE9 ssao_backbuffer_surface;  // full-size ssao backbuffer surface with ordinary backbuffer)
  LPDIRECT3DTEXTURE9 ssao_backbuffer_texture;  // full-size ssao texture
  LPDIRECT3DSURFACE9 ssao_backbuffer_surface2; // full-size ssao backbuffer surface with ordinary backbuffer)
  LPDIRECT3DTEXTURE9 ssao_backbuffer_texture2; // full-size ssao texture

  LPDIRECT3DTEXTURE9 noise_tex;

  // for glow effect
  // 1. render glow objects into the glow_backbuffer.
  // 2. copyrect glow_backbuffer_surface into the glow_downsample_texture.
  // 3. blur glow_downsample_texture into glow_blurred_texture.
  LPDIRECT3DSURFACE9 glow_backbuffer_surface; // full-size glow backbuffer surface with ordinary backbuffer)
  LPDIRECT3DTEXTURE9 glow_backbuffer_texture; // full-size glow texture
  // no need zsurface for glow, but uses normal zsurface.
  LPDIRECT3DTEXTURE9 glow_downsample_texture; // downsampled texture
  LPDIRECT3DSURFACE9 glow_downsample_surface; // downsampled surface
  LPDIRECT3DTEXTURE9 glow_blur_texture;       // blurred final rendertarget texture
  LPDIRECT3DSURFACE9 glow_blur_surface;       // blurred final rendertarget surface

  LPDIRECT3DTEXTURE9 glow_blur_texture_fullscene; // blurred final rendertarget texture for fullscene glow
  LPDIRECT3DSURFACE9 glow_blur_surface_fullscene; // blurred final rendertarget surface for fullscene glow

  bool use_virtual_backbuffer; // whether use virtual backbuffer or not. default is false

  LPDIRECT3DCUBETEXTURE9 normalization_cubemap; // normalization cube map texture

  LPD3DXSPRITE d3d_sprite; // default d3d sprite object

  LPDIRECT3DVERTEXBUFFER9 sprite_vertexbuffer_cover;
  LPDIRECT3DVERTEXBUFFER9 sprite_vertexbuffer_origin;
  LPDIRECT3DVERTEXBUFFER9 sprite_vertexbuffer_origin_ex;

  LPDIRECT3DVERTEXBUFFER9 boundingbox_vertexbuffer;
  LPDIRECT3DINDEXBUFFER9  boundingbox_indexbuffer;

  // pointer to the view class
  zz_view_d3d* view;

  // vertex shader handle
  zz_pool<LPDIRECT3DVERTEXDECLARATION9> vertex_decls;   // =+ always in pair
  zz_pool<LPDIRECT3DVERTEXSHADER9>      vertex_shaders; // =+
  zz_pool<LPDIRECT3DPIXELSHADER9>       pixel_shaders;

  // display mode
  D3DDISPLAYMODE display_mode;
  D3DDISPLAYMODE display_mode_original;
  UINT           adapter_ordinal;
  mat4           modelview_matrix, projection_matrix;
  mat4           world_matrix;

  // renderer state
  D3DCAPS9 device_capability;

  zz_render_state state; // render state

  // d3d format
  D3DFORMAT adapter_format;
  D3DFORMAT rendertarget_format;
  D3DFORMAT depthstencil_format;
  D3DFORMAT backbuffer_format;

  // for shadow map
  LPDIRECT3DSURFACE9 shadowmap_surface; // no need to use shadowmap_zsurface
  LPDIRECT3DTEXTURE9 shadowmap;         // shadowmap texture
  LPDIRECT3DTEXTURE9 shadowmap_forblur; // will be used for blurring
  LPDIRECT3DSURFACE9 shadowmap_forblur_surface;

  // for gamma correction
  D3DGAMMARAMP gamma_ramp;
  zz_gamma     current_gamma;

  zz_camera *  light_camera, *saved_camera;
  D3DVIEWPORT9 old_viewport,  shadowmap_viewport, glow_viewport, glow_downsample_viewport, ssao_viewport;
  D3DVIEWPORT9 default_viewport;
  D3DVIEWPORT9 overlay_viewport;

  LPD3DXMESH sphere_buffer;
  LPD3DXMESH cylinder_buffer;

  std::vector<mat4> matrix_stack;

  static D3DXMATRIX s_mat_id_d3d; // d3d identity matrix

  int          num_polygons_;      // number of rendered polygons in a frame
  int          num_meshes_;        // number of rendered meshes in a frame
  unsigned int max_texture_memory; // maximum(initial) available texture memory by GetAvailableTextureMem
  unsigned int min_texture_memory; // minimum          available texture memory
  //bool create_update_vertex_buffer (zz_mesh * mesh, bool only_update);

  ZZ_RENDERWHERE render_where; // render to where. controlled by begin_scene() end_scene()

  bool     gamma_saved; // whether gamma saved or not
  zz_gamma saved_gamma; // original gamma

  int get_num_adapters();

  bool find_adapter_ordinal(
    D3DDEVTYPE& d3d_dev_type_out,
    UINT&       adapter_ordinal_out,
    bool        use_fullscreen_in,
    D3DFORMAT   adapter_format_in,
    D3DFORMAT   backbuffer_format_in,
    UINT        width_in,
    UINT        height_in,
    UINT        refresh_rate_in);

  // reload texture if the content was modified from beginning
  zz_handle download_texture(zz_texture* tex);
  zz_handle prepare_texture(zz_texture*  tex);

  void log_adapter_identifier(UINT ordinal_in, const D3DADAPTER_IDENTIFIER9& id);

  void fill_shadowmap_vb(); // fill blur vertex buffer
  void fill_glow_vb();      // fill glow vertex buffer

  bool _begin_scene(const char* msg);
  bool _end_scene(const char*   msg);

  bool create_ssao_textures();
  bool create_glow_textures();

  void create_default_sprite();
  void destroy_default_sprite();

public:

  LPDIRECT3DSURFACE9 backbuffer_surface; // real back buffer   //test

  // relates to zz_renderer_d3d lifetime cycle
       zz_renderer_d3d();
       ~zz_renderer_d3d();
  bool initialize() override;
  void cleanup() override;
  bool is_active() override { return (d3d_device != nullptr); }

  // render
  void render(zz_mesh*                mesh, zz_material* material, zz_light* light) override;
  bool draw_indexed_trilist(zz_mesh*  mesh) override;
  bool draw_indexed_tristrip(zz_mesh* mesh) override;
  bool set_stream_buffer(zz_mesh*     mesh) override;
  void set_light(zz_light*            light) override;
  bool set_material(zz_material*      material) override; // return false if not a valid material
  //void render_visible (zz_visible * visible);
  //void render_visibles (void);

  // rendering
  void swap_buffers(HWND hwnd) override;
  void clear_screen() override;
  void clear_zbuffer() override;
  void begin_scene(ZZ_RENDERWHERE render_where) override;
  void end_scene() override;
  bool scene_began() override; // Did the scene begin?
  void init_render_state() override;
  void init_scene() override;
  void init_textures() override;

  // set view pointer
  void     set_view(zz_view* view_to_set) override;
  zz_view* get_view() override;

  // relates to vertex buffer & index buffer
  zz_handle create_vertex_buffer(const zz_device_resource& vres, int       buffer_size) override;
  zz_handle create_index_buffer(const zz_device_resource&  ires, int       buffer_size) override;
  bool      update_vertex_buffer(const zz_device_resource& vres, zz_handle vhandle, const void* buf, int size, int offset) override;
  bool      update_index_buffer(const zz_device_resource&  ires, zz_handle ihandle, const void* buf, int size, int offset) override;
  void      destroy_vertex_buffer(zz_handle                handle_in) override;
  void      destroy_index_buffer(zz_handle                 handle_in) override;

  // vertex shader
  bool set_vertex_shader(zz_handle      shader_index) override;
  int  create_vertex_shader(const char* shader_file_name,
                            int         vertex_format, bool is_binary = false) override;
  void destroy_vertex_shader(int        vertex_shader_handle) override;
  bool support_vertex_shader() override;
  void set_vertex_shader_constant(int        register_index, const void* constant_data, int           coustant_count) override;
  void set_vertex_shader_constant_matrix(int index, const mat4&          matrix_to_set_modelview, int count = 4) override;

  // pixel shader
  bool set_pixel_shader(zz_handle shader_index) override;
  bool support_pixel_shader() override;
  int  create_pixel_shader(const char* shader_file_name, bool is_binary = false) override;
  void destroy_pixel_shader(int        pixel_shader_handle) override;
  void set_pixel_shader_constant(int   register_index, const void* constant_data, int coustant_count) override;

  // texture
  zz_handle create_texture(zz_texture*  tex) override; // create texture into device. returns texture id
  zz_handle update_texture(zz_texture*  tex) override; // reload texture in device. returns texture id
  void      destroy_texture(zz_texture* tex) override; // release texture from device

  bool set_texture(zz_handle texture_handle, int stage, const char* texture_name) override;

  // get d3d texture(LPDIRECT3DTEXTURE9)
  LPDIRECT3DTEXTURE9 get_texture(zz_handle texture_handle);

  //void set_texture_stage_mixmode (zz_material_mixer::zz_material_operation mixmode);
  void set_texture_shadowmap(int shadowmap_stage) override;

  const mat4& get_modelview_matrix() override;
  const mat4& get_projection_matrix() override;
  const mat4& get_world_matrix() override;
  void        set_modelview_matrix(const mat4&  matrix_to_set) override;
  void        set_projection_matrix(const mat4& matrix_to_set) override;
  void        set_world_matrix(const mat4&      matrix_to_set) override;
  void        set_texture_matrix(int            texture_stage, int shader_constant_index, const mat4& matrix_to_set) override;

  // render state
  bool enable_zbuffer(bool       true_or_false) override;
  bool enable_alpha_blend(bool   true_or_false, int blend_type) override;
  bool enable_zwrite(bool        true_or_false) override;
  void enable_fog(bool           true_or_false) override;
  bool enable_alpha_test(bool    true_or_false, ulong alpha_ref = 0x80, ZZ_CMPFUNC cmp_func = ZZ_CMP_GREATEREQUAL) override;
  void set_fog_range(float       fog_start, float     fog_end) override;
  void set_alpha_fog_range(float fog_start, float     fog_end) override;

  zz_render_state* get_state(void                                  ) override;
  void             set_cullmode(zz_render_state::zz_cull_mode_type cullmode) override;

  void matrix_convert(D3DMATRIX& matrix_to_d3d, const mat4&      matrix_from_ogl);
  void matrix_convert(mat4&      matrix_to_ogl, const D3DMATRIX& matrix_from_d3d);

  void matrix_push(const mat4& in_push) override;
  mat4 matrix_pop(void         ) override;

  void draw_line(vec3   from, vec3 to, vec3 rgb) override;
  void draw_arrow(float size, int  color) override;
  void draw_axis(float  size) override;
  void draw_axis(float* q, float* v, float size) override;
  void draw_camera() override;
  void draw_camera_ex(const mat4& view_mat) override;
  void draw_camera(mat4&          camera_matrix);
  void draw_camera_frustum() override;
  void draw_shadowmap();
  void draw_wire_sphere(float               x, float             y, float          z, float          r) override;
  void draw_wire_cylinder(float             x, float             y, float          z, float          length, float r) override;
  void draw_visible_boundingbox(const mat4& matrix, float        min_vec[3], float max_vec[3], DWORD color) override;
  void draw_axis_object(mat4&               object_matrix, float size) override;

  bool set_normalization_cubemap_texture(int stage) override;
  bool create_normalization_cubemap(int      width, int mipmap_level = 5);

  void shadowmap_texturetm_setup(void) override;
  void begin_shadowmap(void          ) override;
  void end_shadowmap(void            ) override;
  void blur_shadowmap(int            repeat_count = 1) override;
  void draw_shadowmap_viewport(void  ) override;

  // resize back buffer by state.screen_width/height
  bool resize() override;

  void set_depthbias(int bias) override;

  LPDIRECT3DDEVICE9 get_device();

  bool has_device() override;

  // gamma control section
  bool set_gamma(const zz_gamma& gamma) override;
  bool get_gamma(zz_gamma&       gamma) override;
  bool set_gamma_by_value(float  gamma_value) override;

  bool set_texture_stage_state(ulong stage, ZZ_TEXTURESTAGESTATETYPE type, ulong     value) override;
  bool set_blend_type(ZZ_BLEND       src, ZZ_BLEND                   dest, ZZ_BLENDOP = ZZ_BLENDOP_ADD) override;

  void draw_texture(float left, float right, float bottom, float top, LPDIRECT3DTEXTURE9 texture, ZZ_BLEND_TYPE blend_type);

  void render_shadowmap_overlay() override;

  void set_sampler_state(int stage, ZZ_SAMPLERSTATETYPE state_type, ulong value) override;

  void           set_render_where(ZZ_RENDERWHERE rwhere_in) override;
  ZZ_RENDERWHERE get_render_where() override;

  bool set_texture_factor(const uivec4& factor) override;

  void set_alpha_ref(int        alpha_ref_in) override;
  bool set_alphafunc(ZZ_CMPFUNC val) override;
  bool set_zfunc(ZZ_CMPFUNC     val) override;

  bool set_render_state(ZZ_RENDERSTATETYPE state, ulong value) override;

  bool save_to_file(const char* filename, int format_dds0_bmp1_jpg2) override;

  DWORD get_fvf(const zz_vertex_format& format);

  bool init_device_objects() override;
  bool invalidate_device_objects() override;
  bool restore_device_objects() override;
  bool delete_device_objects() override;

  unsigned int get_max_texmem() override;       // get max texture memory in bytes.
  unsigned int get_available_texmem() override; // get currently available texture memory in bytes.

  // @spritename for debugging
  bool begin_sprite(int flag, const char* spritename = nullptr) override; // flag = ZZ_SPRITE_XXXXXX in zz_renderer.h
  bool end_sprite() override;
  void init_sprite_state() override;
  void init_sprite_transform(int surface_width, int surface_height) override; // set initial sprite transform
  bool flush_sprite() override;
  bool sprite_began() override;
  bool draw_sprite(zz_texture*       tex, const zz_rect* src_rect, const vec3* center, const vec3* position, color32 color) override;
  bool draw_sprite_ex(zz_texture*    tex, const zz_rect* src_rect, const vec3* center, const vec3* position, color32 color) override;
  bool draw_sprite_cover(zz_texture* tex, const zz_rect* src_rect, const vec3* center, const vec3* position, color32 orgin_color, color32 cover_color, float value) override;

  // only for d3d implementation
  bool         set_sprite_transform(const float* tm); // assumes than *tm* is d3dmatrix. not for znzin
  bool         get_sprite_transform(float*       tm); // assumes that *tm* is d3dmatrix. not for znzin
  LPD3DXSPRITE get_sprite();                          // get system sprite object

  // get renderer cached info
  zz_renderer_cached_info& get_cached_info() override;

  // for statistics
  int get_num_meshes() override;
  int get_num_polygons() override;
  int get_num_textures() override;

  // checks current device states, and reset device if it is necessary.
  // returns device_lost
  bool reset_device() override;

#ifdef _DEBUG
	// only for debugging
	void test();
#endif

  void begin_ssao() override;
  void end_ssao() override;

  void begin_glow() override;
  void end_glow() override;
  void downsample_glow();
  void downsample_glow_fullscene();
  void blur_glow();
  void blur_glow_fullscene();

  // render final blurred glowmap into the backbuffer
  void overlay_glow(bool object_glow, bool fullscene_glow) override;

  void draw_post_process(zz_shader* shader, int pass = 0);

  void pre_process() override;
  void post_process() override;

  static const char* get_hresult_string(HRESULT hr);

  virtual bool check_ssaoable();
  bool         check_glowable() override;
  bool         check_shadowable() override;

  bool support_hw_mouse() override;

  bool validate_device() override;

  void invalidate_texture(int stage) override;

  void get_viewport(zz_viewport& viewport) override;

  void set_viewport(const zz_viewport& viewport) override;

  bool support_color_write() override;

  void enable_color_write(dword flag) override;

  int get_num_simultaneous_render_target() override;

  bool check_rendertarget32();

  const D3DXMATRIX& get_mat_id_d3d() const {
    return s_mat_id_d3d;
  }

  bool get_device_lost() const override {
    return _device_lost;
  }

  // wait during device lost state
  void wait_device_lost();

  // destroy and create the default sprite.
  // this is used for recovery when the exception was occured in drawing by sprite
  // for now, this is used only in zz_font_d3d
  void recreate_default_sprite() {
    destroy_default_sprite();
    create_default_sprite();
  }

ZZ_DECLARE_DYNAMIC(zz_renderer_d3d)
};

inline LPDIRECT3DDEVICE9 zz_renderer_d3d::get_device() {
  return (is_active()) ? d3d_device : nullptr;
}

inline bool zz_renderer_d3d::set_texture_factor(const uivec4& factor) {
  if ( FAILED(d3d_device->SetRenderState(D3DRS_TEXTUREFACTOR, D3DCOLOR_RGBA(factor.x, factor.y, factor.z, factor.w))) ) {
    return false;
  }
  return true;
}

inline bool zz_renderer_d3d::set_texture_stage_state(ulong stage, ZZ_TEXTURESTAGESTATETYPE type, ulong value) {
  if ( FAILED(d3d_device->SetTextureStageState(stage, static_cast<D3DTEXTURESTAGESTATETYPE>(type), value)) )
    return false;
  return true;
}

inline void zz_renderer_d3d::set_sampler_state(int stage, ZZ_SAMPLERSTATETYPE state_type, ulong value) {
  d3d_device->SetSamplerState( stage, D3DSAMPLERSTATETYPE( int( state_type ) ), value );
}

inline bool zz_renderer_d3d::scene_began() {
  return _scene_began;
}

inline void zz_renderer_d3d::set_render_where(ZZ_RENDERWHERE rwhere_in) {
  render_where = rwhere_in;
}

inline ZZ_RENDERWHERE zz_renderer_d3d::get_render_where() {
  return render_where;
}

inline LPD3DXSPRITE zz_renderer_d3d::get_sprite() {
  return d3d_sprite;
}

#endif // __ZZ_RENDERER_D3D_H__
