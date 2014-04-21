#ifndef _ROS_ardrone_autonomy_navdata_demo_h
#define _ROS_ardrone_autonomy_navdata_demo_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace ardrone_autonomy
{

  class navdata_demo : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float drone_time;
      uint16_t tag;
      uint16_t size;
      uint32_t ctrl_state;
      uint32_t vbat_flying_percentage;
      float theta;
      float phi;
      float psi;
      int32_t altitude;
      float vx;
      float vy;
      float vz;
      uint32_t num_frames;
      uint32_t detection_camera_type;

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
      *(outbuffer + offset + 0) = (this->ctrl_state >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->ctrl_state >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->ctrl_state >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->ctrl_state >> (8 * 3)) & 0xFF;
      offset += sizeof(this->ctrl_state);
      *(outbuffer + offset + 0) = (this->vbat_flying_percentage >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->vbat_flying_percentage >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->vbat_flying_percentage >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->vbat_flying_percentage >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vbat_flying_percentage);
      union {
        float real;
        uint32_t base;
      } u_theta;
      u_theta.real = this->theta;
      *(outbuffer + offset + 0) = (u_theta.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_theta.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_theta.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_theta.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->theta);
      union {
        float real;
        uint32_t base;
      } u_phi;
      u_phi.real = this->phi;
      *(outbuffer + offset + 0) = (u_phi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_phi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_phi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_phi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->phi);
      union {
        float real;
        uint32_t base;
      } u_psi;
      u_psi.real = this->psi;
      *(outbuffer + offset + 0) = (u_psi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_psi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_psi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_psi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->psi);
      union {
        int32_t real;
        uint32_t base;
      } u_altitude;
      u_altitude.real = this->altitude;
      *(outbuffer + offset + 0) = (u_altitude.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_altitude.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_altitude.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_altitude.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_vx;
      u_vx.real = this->vx;
      *(outbuffer + offset + 0) = (u_vx.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vx.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vx.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vx.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vx);
      union {
        float real;
        uint32_t base;
      } u_vy;
      u_vy.real = this->vy;
      *(outbuffer + offset + 0) = (u_vy.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vy.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vy.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vy.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vy);
      union {
        float real;
        uint32_t base;
      } u_vz;
      u_vz.real = this->vz;
      *(outbuffer + offset + 0) = (u_vz.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_vz.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_vz.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_vz.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->vz);
      *(outbuffer + offset + 0) = (this->num_frames >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->num_frames >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->num_frames >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->num_frames >> (8 * 3)) & 0xFF;
      offset += sizeof(this->num_frames);
      *(outbuffer + offset + 0) = (this->detection_camera_type >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->detection_camera_type >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->detection_camera_type >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->detection_camera_type >> (8 * 3)) & 0xFF;
      offset += sizeof(this->detection_camera_type);
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
      this->ctrl_state =  ((uint32_t) (*(inbuffer + offset)));
      this->ctrl_state |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->ctrl_state |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->ctrl_state |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->ctrl_state);
      this->vbat_flying_percentage =  ((uint32_t) (*(inbuffer + offset)));
      this->vbat_flying_percentage |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->vbat_flying_percentage |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->vbat_flying_percentage |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->vbat_flying_percentage);
      union {
        float real;
        uint32_t base;
      } u_theta;
      u_theta.base = 0;
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_theta.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->theta = u_theta.real;
      offset += sizeof(this->theta);
      union {
        float real;
        uint32_t base;
      } u_phi;
      u_phi.base = 0;
      u_phi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_phi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_phi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_phi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->phi = u_phi.real;
      offset += sizeof(this->phi);
      union {
        float real;
        uint32_t base;
      } u_psi;
      u_psi.base = 0;
      u_psi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_psi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_psi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_psi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->psi = u_psi.real;
      offset += sizeof(this->psi);
      union {
        int32_t real;
        uint32_t base;
      } u_altitude;
      u_altitude.base = 0;
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_altitude.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->altitude = u_altitude.real;
      offset += sizeof(this->altitude);
      union {
        float real;
        uint32_t base;
      } u_vx;
      u_vx.base = 0;
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vx.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vx = u_vx.real;
      offset += sizeof(this->vx);
      union {
        float real;
        uint32_t base;
      } u_vy;
      u_vy.base = 0;
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vy.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vy = u_vy.real;
      offset += sizeof(this->vy);
      union {
        float real;
        uint32_t base;
      } u_vz;
      u_vz.base = 0;
      u_vz.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_vz.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_vz.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_vz.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->vz = u_vz.real;
      offset += sizeof(this->vz);
      this->num_frames =  ((uint32_t) (*(inbuffer + offset)));
      this->num_frames |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->num_frames |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->num_frames |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->num_frames);
      this->detection_camera_type =  ((uint32_t) (*(inbuffer + offset)));
      this->detection_camera_type |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->detection_camera_type |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->detection_camera_type |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->detection_camera_type);
     return offset;
    }

    const char * getType(){ return "ardrone_autonomy/navdata_demo"; };
    const char * getMD5(){ return "5f569653293c884e2ea43f113057d0ea"; };

  };

}
#endif