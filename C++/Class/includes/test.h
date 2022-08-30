#include <iostream>

using namespace std;

class VESC_VALUES{
    public:
        float temp_fet = 0;
        float temp_motor = 0;
        float motor_current = 0;
        float input_current = 0;
        float id_current = 0;
        float iq_current = 0;
        float duty = 0;
        float erpm = 0;
        float volt_input = 0;
        float amp_hours = 0;
        float amp_hours_charged = 0;
        float watt_hours = 0;
        float watt_hours_charged = 0;
        float tacho = 0;
        float tacho_abs = 0;
        float fault = 0;
        float pid_pos_now = 0;
        float controller_id = 0;
        float temp_mos1 = 0;
        float temp_mos2 = 0;
        float temp_mos3 = 0;
        float vd_volt = 0;
        float vq_volt = 0;

};

class VESC_PACKET{
    public :
            VESC_VALUES vesc;
}