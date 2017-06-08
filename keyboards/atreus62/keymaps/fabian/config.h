#define ONESHOT_TIMEOUT 3000
#define TAPPING_TERM 200
#define PREVENT_STUCK_MODIFIERS
#define FORCE_NKRO
#define LEADER_TIMEOUT 1000

#include "../../config.h"

#define LSPO_KEY KC_8
#define RSPC_KEY KC_9

#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    60
#define MOUSEKEY_MAX_SPEED      7
#define MOUSEKEY_WHEEL_DELAY 0


#undef IS_COMMAND
#define IS_COMMAND() ( FALSE)