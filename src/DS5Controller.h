#pragma once

#include <godot_cpp/godot.hpp>
#include <godot_cpp/classes/object.hpp>

using namespace godot;

class DS5Controller : public godot::Object
{
    GDCLASS(DS5Controller, godot::Object)

public:
    DS5Controller();
    ~DS5Controller();
    
    static int start();
    static void _bind_methods();

};