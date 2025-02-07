cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

set(PROJECT znzin)
project(${PROJECT})

include_directories(
  SYSTEM ${SPDLOG_ROOT}
  SYSTEM ${DIRECTX_ROOT}/include
  SYSTEM ${CMAKE_THIRD_PARTY_INCLUDE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if (64BIT)
  link_directories(${DIRECTX_ROOT}/lib/x64)
else()
  link_directories(${DIRECTX_ROOT}/lib)
endif()

link_directories(
  ${CMAKE_EXTERNAL_LIBRARY_DIR}
  ${CMAKE_THIRD_PARTY_LIBRARY_DIR}
)

add_linker_flags("/NODEFAULTLIB:\"libcp.lib\"")
add_linker_flags("/SAFESEH:NO")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DZZ_DLL_EXPORT")

set(args
  TARGET znzin
  LUAFILES include/zz_version_info.lua include/zz_script_lua.lua
  LUAROOT ${CMAKE_CURRENT_SOURCE_DIR}/include
)

generate_lua_includes(LUA_HEADERS ${args})

set( SOURCES_HEADER
  include/zz_algebra.h
  include/zz_animatable.h
  include/zz_array.h
  include/zz_assert.h
  include/zz_autolock.h
  include/zz_bone.h
  include/zz_build_count
  include/zz_bvolume.h
  include/zz_bvolume_obb.h
  include/zz_camera.h
  include/zz_camera_follow.h
  include/zz_channel.h
  include/zz_channel_position.h
  include/zz_channel_rotation.h
  include/zz_channel_x.h
  include/zz_channel_xy.h
  include/zz_critical_section.h
  include/zz_cursor.h
  include/zz_db.h
  include/zz_device_resource.h
  include/zz_dx_version.h
  include/zz_error.h
  include/zz_event.h
  include/zz_font.h
  include/zz_font_d3d.h
  include/zz_font_texture.h
  include/zz_font_texture_d3d.h
  include/zz_gamma.h
  include/zz_hash_table.h
  include/zz_ik_limb.h
  include/zz_index_buffer.h
  include/zz_interface.h
  include/zz_light.h
  include/zz_light_direct.h
  include/zz_light_omni.h
  include/zz_light_point.h
  include/zz_list.h
  include/zz_lod.h
  include/zz_log.h
  include/zz_macro.h
  include/zz_manager.h
  include/zz_manager_font.h
  include/zz_manager_mesh_ishared.h
  include/zz_manager_sound.h
  include/zz_manager_texture.h
  include/zz_manager_visible.h
  include/zz_material.h
  include/zz_material_colormap.h
  include/zz_material_ocean.h
  include/zz_material_sky.h
  include/zz_material_terrain.h
  include/zz_mem.h
  include/zz_mesh.h
  include/zz_mesh_ishared.h
  include/zz_mesh_ocean.h
  include/zz_mesh_terrain.h
  include/zz_mesh_tool.h
  include/zz_minmax.h
  include/zz_misc.h
  include/zz_mode.h
  include/zz_model.h
  include/zz_morpher.h
  include/zz_motion.h
  include/zz_motion_controller.h
  include/zz_motion_mixer.h
  include/zz_motion_tool.h
  include/zz_node.h
  include/zz_node_type.h
  include/zz_ocean_block.h
  include/zz_octree.h
  include/zz_os.h
  include/zz_oskernel.h
  include/zz_particle.h
  include/zz_particle_emitter.h
  include/zz_particle_event.h
  include/zz_particle_event_sequence.h
  include/zz_path.h
  include/zz_pointer.h
  include/zz_pool.h
  include/zz_primitive.h
  include/zz_profiler.h
  include/zz_recycling_array.h
  include/zz_refcount.h
  include/zz_renderer.h
  include/zz_renderer_d3d.h
  include/zz_render_state.h
  include/zz_scene.h
  include/zz_scene_octree.h
  include/zz_script.h
  include/zz_script_lua.h
  include/zz_script_lua.lua
  include/zz_script_simple.h
  include/zz_sfx.h
  include/zz_shader.h
  include/zz_skeleton.h
  include/zz_sky.h
  include/zz_sound.h
  include/zz_string.h
  include/zz_system.h
  include/zz_targa.h
  include/zz_terrain.h
  include/zz_terrain_block.h
  include/zz_texture.h
  include/zz_thread.h
  include/zz_tier0.h
  include/zz_timer.h
  include/zz_trail.h
  include/zz_tree.h
  include/zz_type.h
  include/zz_unit_test.h
  include/zz_version_info.lua
  include/zz_vertex_buffer.h
  include/zz_vertex_format.h
  include/zz_vfs.h
  include/zz_vfs_local.h
  include/zz_vfs_mem.h
  include/zz_vfs_pkg.h
  include/zz_vfs_thread.h
  include/zz_vfs_zip.h
  include/zz_view.h
  include/zz_viewfrustum.h
  include/zz_view_d3d.h
  include/zz_visible.h
  include/zz_waiting_line.h
)

set( SOURCES_MAIN
  src/zz_algebra.cpp
  src/zz_animatable.cpp
  src/zz_assert.cpp
  src/zz_bone.cpp
  src/zz_bvolume.cpp
  src/zz_bvolume_obb.cpp
  src/zz_camera.cpp
  src/zz_camera_follow.cpp
  src/zz_channel.cpp
  src/zz_channel_position.cpp
  src/zz_channel_rotation.cpp
  src/zz_channel_x.cpp
  src/zz_channel_xy.cpp
  src/zz_cursor.cpp
  src/zz_db.cpp
  src/zz_dx_version.cpp
  src/zz_error.cpp
  src/zz_event.cpp
  src/zz_font.cpp
  src/zz_font_d3d.cpp
  src/zz_font_texture.cpp
  src/zz_font_texture_d3d.cpp
  src/zz_gamma.cpp
  src/zz_ik_limb.cpp
  src/zz_index_buffer.cpp
  src/zz_interface.cpp
  src/zz_light.cpp
  src/zz_light_direct.cpp
  src/zz_light_omni.cpp
  src/zz_light_point.cpp
  src/zz_lod.cpp
  src/zz_log.cpp
  src/zz_main.cpp
  src/zz_manager.cpp
  src/zz_manager_font.cpp
  src/zz_manager_mesh_ishared.cpp
  src/zz_manager_sound.cpp
  src/zz_manager_texture.cpp
  src/zz_manager_visible.cpp
  src/zz_material.cpp
  src/zz_material_colormap.cpp
  src/zz_material_ocean.cpp
  src/zz_material_sky.cpp
  src/zz_material_terrain.cpp
  src/zz_mem.cpp
  src/zz_mesh.cpp
  src/zz_mesh_ishared.cpp
  src/zz_mesh_ocean.cpp
  src/zz_mesh_terrain.cpp
  src/zz_mesh_tool.cpp
  src/zz_misc.cpp
  src/zz_model.cpp
  src/zz_morpher.cpp
  src/zz_motion.cpp
  src/zz_motion_controller.cpp
  src/zz_motion_mixer.cpp
  src/zz_motion_tool.cpp
  src/zz_node.cpp
  src/zz_node_type.cpp
  src/zz_ocean_block.cpp
  src/zz_octree.cpp
  src/zz_os.cpp
  src/zz_particle.cpp
  src/zz_particle_emitter.cpp
  src/zz_particle_event.cpp
  src/zz_particle_event_sequence.cpp
  src/zz_path.cpp
  src/zz_primitive.cpp
  src/zz_profiler.cpp
  src/zz_renderer.cpp
  src/zz_renderer_d3d.cpp
  src/zz_render_state.cpp
  src/zz_scene.cpp
  src/zz_scene_octree.cpp
  src/zz_script.cpp
  src/zz_script_lua.cpp
  src/zz_script_simple.cpp
  src/zz_sfx.cpp
  src/zz_shader.cpp
  src/zz_skeleton.cpp
  src/zz_sky.cpp
  src/zz_sound.cpp
  src/zz_string.cpp
  src/zz_system.cpp
  src/zz_targa.cpp
  src/zz_terrain.cpp
  src/zz_terrain_block.cpp
  src/zz_texture.cpp
  src/zz_thread.cpp
  src/zz_timer.cpp
  src/zz_trail.cpp
  src/zz_unit_test.cpp
  src/zz_vertex_buffer.cpp
  src/zz_vfs.cpp
  src/zz_vfs_local.cpp
  src/zz_vfs_mem.cpp
  src/zz_vfs_pkg.cpp
  src/zz_vfs_thread.cpp
  src/zz_vfs_zip.cpp
  src/zz_view.cpp
  src/zz_view_d3d.cpp
  src/zz_visible.cpp
  src/zz_waiting_line.cpp
)

add_library(${PROJECT} SHARED ${SOURCES_MAIN} ${SOURCES_HEADER} ${LUA_HEADERS})
target_include_directories(${PROJECT} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
set_target_properties(${PROJECT} PROPERTIES OUTPUT_NAME_DEBUG "znzin_d")

add_dependencies(${PROJECT} znzin_generated)
if(NOT LUA_FOUND)
  add_dependencies(${PROJECT} lua::lua5)
endif()
target_link_libraries(${PROJECT} PUBLIC legacy_stdio_definitions.lib d3d9.lib d3dx9.lib version.lib Winmm.lib)
target_link_libraries(${PROJECT} PUBLIC lua::lua5)
target_link_libraries(${PROJECT} PUBLIC TriggerVFS)
