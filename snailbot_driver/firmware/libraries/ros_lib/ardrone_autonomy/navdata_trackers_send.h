#ifndef _ROS_ardrone_autonomy_navdata_trackers_send_h
#define _ROS_ardrone_autonomy_navdata_trackers_send_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "ardrone_autonomy/vector21.h"

namespace ardrone_autonomy
{

  class navdata_trackers_send : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float drone_time;
      uint16_t tag;
      uint16_t size;
      uint8_t locked_length;
      int32_t st_locked;
      int32_t * locked;
      uint8_t point_length;
      ardrone_autonomy::vector21 st_point;
      ardrone_autonomy::vector21 * point;

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      int32_t * val_drone_time = (int32_t *) &(this->drone_time);
      int32_t exp_drone_time = (((*val_drone_time)>>23)&255);
      if(exp_drone_time != 0)
        exp_drone_time += 1023-127;
      int32_t sig_drone_time = *val_drone_time;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = (sig_drone_time<<5) & 0xff;
      *(outbuffer + offset++) = (sig_drone_time>>3) & 0xff;
      *(outbuffer + offset++) = (sig_drone_time>>11) & 0xff;
      *(outbuffer + offset++) = ((exp_drone_time<<4) & 0xF0) | ((sig_drone_time>>19)&0x0F);
      *(outbuffer + offset++) = (exp_drone_time>>4) & 0x7F;
      if(this->drone_time < 0) *(outbuffer + offset -1) |= 0x80;
      *(outbuffer + offset + 0) = (this->tag >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tag >> (8 * 1)) & 0xFF;
      offset += sizeof(this->tag);
      *(outbuffer + offset + 0) = (this->size >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->size >> (8 * 1)) & 0xFF;
      offset += sizeof(this->size);
      *(outbuffer + offset++) = locked_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < locked_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_lockedi;
      u_lockedi.real = this->locked[i];
      *(outbuffer + offset + 0) = (u_lockedi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_lockedi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_lockedi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_lockedi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->locked[i]);
      }
      *(outbuffer + offset++) = point_length;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      *(outbuffer + offset++) = 0;
      for( uint8_t i = 0; i < point_length; i++){
      offset += this->point[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t * val_drone_time = (uint32_t*) &(this->drone_time);
      offset += 3;
      *val_drone_time = ((uint32_t)(*(inbuffer + offset++))>>5 & 0x07);
      *val_drone_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<3;
      *val_drone_time |= ((uint32_t)(*(inbuffer + offset++)) & 0xff)<<11;
      *val_drone_time |= ((uint32_t)(*(inbuffer + offset)) & 0x0f)<<19;
      uint32_t exp_drone_time = ((uint32_t)(*(inbuffer + offset++))&0xf0)>>4;
      exp_drone_time |= ((uint32_t)(*(inbuffer + offset)) & 0x7f)<<4;
      if(exp_drone_time !=0)
        *val_drone_time |= ((exp_drone_time)-1023+127)<<23;
      if( ((*(inbuffer+offset++)) & 0x80) > 0) this->drone_time = -this->drone_time;
      this->tag =  ((uint16_t) (*(inbuffer + offset)));
      this->tag |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->tag);
      this->size =  ((uint16_t) (*(inbuffer + offset)));
      this->size |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->size);
      uint8_t locked_lengthT = *(inbuffer + offset++);
      if(locked_lengthT > locked_length)
        this->locked = (int32_t*)realloc(this->locked, locked_lengthT * sizeof(int32_t));
      offset += 3;
      locked_length = locked_lengthT;
      for( uint8_t i = 0; i < locked_length; i++){
      union {
        int32_t real;
        uint32_t base;
      } u_st_locked;
      u_st_locked.base = 0;
      u_st_locked.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_locked.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_st_locked.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_st_locked.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->st_locked = u_st_locked.real;
      offset += sizeof(this->st_locked);
        memcpy( &(this->locked[i]), &(this->st_locked), sizeof(int32_t));
      }
      uint8_t point_lengthT = *(inbuffer + offset++);
      if(point_lengthT > point_length)
        this->point = (ardrone_autonomy::vector21*)realloc(this->point, point_lengthT * sizeof(ardrone_autonomy::vector21));
      offset += 3;
      point_length = point_lengthT;
      for( uint8_t i = 0; i < point_length; i++){
      offset += this->st_point.deserialize(inbuffer + offset);
        memcpy( &(this->point[i]), &(this->st_point), sizeof(ardrone_autonomy::vector21));
      }
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_trackers_send"; };
    const char * getMD5(){ return "77326ae58ca7691bcd2f23425242a70e"; };

  };

}
#endif