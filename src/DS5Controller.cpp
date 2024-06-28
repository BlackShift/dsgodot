#include "DS5Controller.h"
#include <godot_cpp/core/class_db.hpp>
#include "../DualSenseWindows/Device.h"
#include "../DualSenseWindows/IO.h"
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

DS5Controller::DS5Controller()
{
}
DS5Controller::~DS5Controller()
{
}
void DS5Controller::_bind_methods()
{
    ClassDB::bind_static_method("DS5Controller",D_METHOD("start"), &DS5Controller::start);
}

int DS5Controller::start()
{
    DS5W::DeviceEnumInfo infos[16];

    unsigned int controllerCount = 0;

    switch (DS5W::enumDevices(infos,16, &controllerCount))
    {
    case DS5W_OK:
        break;
    case DS5W_E_INSUFFICIENT_BUFFER:
        break;
    default:
        return -1;
    }
    UtilityFunctions::print("Found DualSense2 controllers: ",controllerCount);
    return 0;
}