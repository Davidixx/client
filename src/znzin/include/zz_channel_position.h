/** 
 * @file zz_channel_position.h
 * @brief channel_position struct.
 * @author Jiho Choi (zho@korea.com)
 * @version 1.0
 * @date    02-jun-2002
 *
 * $Header: /engine/include/zz_channel_position.h 2     04-07-07 3:29a Zho $
 */

#ifndef	__ZZ_CHANNEL_POSITION_H__
#define __ZZ_CHANNEL_POSITION_H__

#include <vector>

#ifndef __ZZ_CHANNEL_H__
#include "zz_channel.h"
#endif

class zz_motion;

//--------------------------------------------------------------------------------
class zz_channel_position : public zz_channel {
  friend class zz_motion;

protected:
  vec3*        positions;
  unsigned int num_positions;

public:
          zz_channel_position(void );
  virtual ~zz_channel_position(void);

  // vector related
  void assign(int size) override;
  void clear(void ) override;
  int  size(void  ) override;

  // set methods
  void get_by_frame(int    frame, void* data_pointer) override;
  void get_by_time(zz_time time, int    fps, void* data_pointer) override;

  // set methods
  void set_by_frame(int frame, void* data_pointer) override;
};

#endif // __ZZ_CHANNEL_POSITION_H__
