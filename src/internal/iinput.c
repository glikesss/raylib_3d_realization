#include "../raylib/raylib.h"
#include "iactions.h"


typedef struct{
    KeyboardKey key;
    bool ctrl;
    bool shift;
    bool alt;
    bool super;
} KeyCombo;

typedef struct{
    MouseButton button;
    bool ctrl;
    bool shift;
    bool alt;
    bool super;
} MouseCombo;


#define COMBO_MOVE_POINT_X (MouseCombo){        \
        .button  = MOUSE_LEFT_BUTTON,           \
            .ctrl    = true                     \
            }                                   \
    
#define COMBO_MOVE_POINT_Y (MouseCombo){        \
        .button  = MOUSE_LEFT_BUTTON,           \
            .shift   = true                     \
            }                                   \

#define COMBO_ROTATE_POINT_X_AXIS_CV (KeyCombo){    \
        .key  = KEY_D,                              \
            }                                       \
    

#define COMBO_ROTATE_POINT_X_AXIS_CCV (KeyCombo){   \
        .key  = KEY_A,                              \
            }                                       \
    
#define COMBO_ROTATE_POINT_Y_AXIS_CV (KeyCombo){    \
        .key  = KEY_W,                              \
            }                                       \
    
#define COMBO_ROTATE_POINT_Y_AXIS_CCV (KeyCombo){   \
        .key  = KEY_S,                              \
            }                                       \
    
#define COMBO_ROTATE_POINT_Z_AXIS_CV (KeyCombo){    \
        .key  = KEY_W,                              \
            .ctrl = true                            \
            }                                       \
    
#define COMBO_ROTATE_POINT_Z_AXIS_CCV (KeyCombo){   \
        .key  = KEY_S,                              \
            .ctrl = true                            \
            }                                       \
    


bool IsComboPressedDown(KeyCombo combo){
    return IsKeyDown(combo.key)  
        && (IsKeyDown(KEY_LEFT_CONTROL)  == combo.ctrl
        ||  IsKeyDown(KEY_RIGHT_CONTROL) == combo.ctrl)
        && (IsKeyDown(KEY_LEFT_SHIFT)    == combo.shift
        || IsKeyDown(KEY_RIGHT_SHIFT)    == combo.shift)
        && (IsKeyDown(KEY_LEFT_ALT)      == combo.alt
        || IsKeyDown(KEY_RIGHT_ALT)      == combo.alt)
        && (IsKeyDown(KEY_LEFT_SUPER)    == combo.super
        || IsKeyDown(KEY_RIGHT_SUPER)    == combo.super);
}

