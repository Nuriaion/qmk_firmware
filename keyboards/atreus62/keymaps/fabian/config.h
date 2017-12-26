#include "stdbool.h"

#define ONESHOT_TIMEOUT 3000
#define TAPPING_TERM 200
#define PREVENT_STUCK_MODIFIERS
#define FORCE_NKRO
#define LEADER_TIMEOUT 1000

#include "../../config.h"

#define LSPO_KEY KC_8
#define RSPC_KEY KC_9

#undef IS_COMMAND
#define IS_COMMAND() ( false)
