/**
 * Auto-generated global data definitions
 * Binary: Game.exe
 */

#include "globals/globals.h"
#include "D2Client/UNIT/Item.h"
#include "D2Client/UNIT/Missile.h"
#include "D2Client/UNIT/Monster.h"
#include "D2Client/UNIT/Object.h"
#include "D2Client/UNIT/Player.h"
#include "D2Game/D2Game.h"
#include "D2Game/D2QuestDataStrc.h"
#include "D2Game/GAME/Event/Dispatch/Monster.h"
#include "D2Game/GAME/Server.h"
#include "D2Game/GAME/Task.h"
#include "D2Game/ITEMS/ItemMode.h"
#include "D2Game/MISSILES/MissilesMode.h"
#include "D2Game/MISSILES/MissilesMode/SrvDoFunc.h"
#include "D2Game/Monster/AI/AI.h"
#include "D2Game/Monster/Monsters.h"
#include "D2Game/Monsters/Umod.h"
#include "D2Game/Objects/ArmorWeapon.h"
#include "D2Game/Objects/Objects.h"
#include "D2Game/Objects/ObjectsMode.h"
#include "D2Game/PLAYER/PlayerModes.h"
#include "D2Game/PLAYER/PlayerMsg.h"
#include "D2Game/PLAYER/PlayerTrade.h"
#include "D2Game/Quests/QUESTS.h"
#include "D2Game/Quests/QUESTS/A1Q3.h"
#include "D2Game/Quests/QUESTS/A1Q4.h"
#include "D2Game/Quests/QUESTS/A1Q5.h"
#include "D2Game/Quests/QUESTS/A2Q2.h"
#include "D2Game/Quests/QUESTS/A2Q3.h"
#include "D2Game/Quests/QUESTS/A2Q4.h"
#include "D2Game/Quests/QUESTS/A2Q7.h"
#include "D2Game/Quests/QUESTS/A3Q1.h"
#include "D2Game/Quests/QUESTS/A3Q2.h"
#include "D2Game/Quests/QUESTS/A3Q3.h"
#include "D2Game/Quests/QUESTS/A3Q5.h"
#include "D2Game/Quests/QUESTS/A4Q2.h"
#include "D2Game/Quests/QUESTS/A4Q3.h"
#include "D2Game/Quests/QUESTS/A5Q3.h"
#include "D2Game/Quests/QUESTS/A5Q5.h"
#include "D2Game/Quests/QUESTS/A5Q6.h"
#include "D2Game/SKILLS/SkillAma.h"
#include "D2Game/SKILLS/SkillAss.h"
#include "D2Game/SKILLS/SkillBar.h"
#include "D2Game/SKILLS/SkillDruid.h"
#include "D2Game/SKILLS/SkillEMonst.h"
#include "D2Game/SKILLS/SkillItem.h"
#include "D2Game/SKILLS/SkillMonst.h"
#include "D2Game/SKILLS/SkillNec.h"
#include "D2Game/SKILLS/SkillPal.h"
#include "D2Game/SKILLS/SkillSor.h"
#include "D2Game/SKILLS/SkillsServer.h"
#include "D2Game/UNIT/sunitproxy.h"
#include "Storm/_unnamespaced.h"


// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NET_SERVER_D2GS_ClientToServer NET_D2GS_SERVER_INCOMING[103] = {
    {
        /* .fpHandler = */ nullptr,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x01_WalkToLocation,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x02_WalkToEntity,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x03_RunToLocation,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x04_RunToEntity,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x05_LeftSkillOnLocation,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x06_LeftSkillOnEntity,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x07_LeftSkillOnEntityEx,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x08_LeftSkillOnLocationEx,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::PLRMSG_Cmd0x09_CheckRangeThenLeftSkillOnEntity,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x0A_LeftSkillOnEntityEx3,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x0B_Keepalive,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x0C_RightSkillOnLocation,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x0D_RightSkillOnEntity,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x0E_RightSkillOnEntityEx,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x0F_RightSkillOnLocationEx,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::PLRMSG_Cmd0x10_CheckRangeThenRightSkillOnEntity,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x11_RightSkillOnEntityEx3,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x12_CancelChanneledSkill,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x13_InteractWithEntity,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x14_OverheadMessage,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x15_ChatMessage,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x16_InteractWithEntityEx,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x17_DropItem,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x18_ItemToInventory,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x19_PickUpToCursor,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x1A_EquipItem,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x1B_EquipToSwapSlot,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x1C_UnequipToInventory,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x1D_SwapBodyItem,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x1E_EquipToWeaponSwap,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x1F_UseItem,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x20_UseItemAtLocation,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x21_MergeStackables,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::PLRMSG_Cmd0x22_RemoveStackItem,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x23_ItemToBelt,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x24_ItemFromBelt,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x25_SwapBeltItem,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x26_UseItemAtPlayerCoords,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x27_UseItemOnItem,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x28_SocketItem,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x29_ScrollIntoBook,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x2A_ItemToCube,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ nullptr,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::PLRMSG_Cmd0x2C_ReturnBadParams,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::PLRMSG_Cmd0x2D_ReturnBadParams,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::PLRMSG_Cmd0x2E_ReturnOk,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x2F_NpcInteract,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x30_NpcCancelDialog,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x31_NpcGossip,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x32_NpcBuyConfirm,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x33_NpcSell,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x34_CainIdentify,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x35_NpcGamble,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x36_HireMerc,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x37_GambleConfirm,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x38_NpcMenuSelect,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ &D2Game::PLAYER::PlayerMsg::PLRMSG_Cmd0x39_ReturnBadParams,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x3A_AllocStatPoint,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x3B_AllocSkillPoint,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x3C_SelectSkill,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x3D_ActivateObject,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x3E_QuestItemPickup,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x3F_PlayEmote,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x40_RefreshQuestData,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x41_Resurrect,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ &D2Game::PLAYER::PlayerMsg::SCMD_0x42_StaffInOrifice1,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ &D2Game::PLAYER::PlayerMsg::SCMD_0x43_StaffInOrifice2,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x44_StaffInOrifice,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ &D2Game::PLAYER::PlayerMsg::SCMD_0x45_Unused,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x46_NpcInteractMerc,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x47_CommandMercenary,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x48_ConfirmTradeTick,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x49_TakeWaypoint,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ nullptr,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x4B_ForceUnitUpdate,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x4C_TransmogrifyItem2,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x4D_ResetNpcIntroFlag,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ nullptr,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x4F_GoToTownFolk,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x50_DropGold,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x51_SetHotkey,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x52_Unused,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x53_GamepadInput,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x54_StopRunning,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ nullptr,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ nullptr,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ nullptr,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x58_MarkQuestDone,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x59_CommandNPC,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ nullptr,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ nullptr,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ nullptr,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x5D_CubeRecipeCheck,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x5E_CubeApply,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ &D2Game::PLAYER::PlayerMsg::SCMD_0x5F_SyncPosition,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x60_WeaponSwap,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x61_MercEquipItem,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x62_NpcSellExpansion,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::SCMD_0x63_ItemToBeltAuto,
        /* .field1_0x4 = */ 0x1
    },
    {
        /* .fpHandler = */ nullptr,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ nullptr,
        /* .field1_0x4 = */ 0x0
    },
    {
        /* .fpHandler = */ (D2NET_SERVER_CLTtoD2GS)&D2Game::PLAYER::PlayerMsg::PLRMSG_Cmd0x66_WardenResponse_ReturnOk,
        /* .field1_0x4 = */ 0x0
    }
};

int ganUnitHashTableBaseOffsets[6] = { 0x1120, 0x1320, 0x1520, 0x1920, 0x1720, 0x0 };

uint32_t gaStartingLevelByAct[5] = { 0x1, 0xf, 0x14, 0x1a, 0x20 };

uint32_t PlayerMultiplyer[9] = {
    0x0,
    0x0,
    0x32,
    0x64,
    0x96,
    0xc8,
    0xfa,
    0x12c,
    0x15e
};

uint32_t PlayerMultiplyer2[9] = {
    0x0,
    0x0,
    0x32,
    0x64,
    0x96,
    0xc8,
    0xfa,
    0x12c,
    0x15e
};

D2PlayerModeFnPairStrc gaPlayerModeMoveFuncs[20] = {
    {
        /* .pfnMoveToLocation = */ nullptr,
        /* .pfnStartMode = */ &D2Game::PLAYER::PlayerModes::PLRMODES_Death
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_SetIdleMode,
        /* .pfnStartMode = */ nullptr
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_SetMoveTargetPosition,
        /* .pfnStartMode = */ &D2Game::PLAYER::PlayerModes::PLRMODES_SetTargetAndStartPath
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_SetMoveTargetPosition,
        /* .pfnStartMode = */ &D2Game::PLAYER::PlayerModes::PLRMODES_SetTargetAndStartPath
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_ChangeAnimModeAndResetSkill,
        /* .pfnStartMode = */ nullptr
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_SetIdleMode,
        /* .pfnStartMode = */ nullptr
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_SetMoveTargetPosition,
        /* .pfnStartMode = */ &D2Game::PLAYER::PlayerModes::PLRMODES_SetTargetAndStartPath
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtPosition,
        /* .pfnStartMode = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtEntity
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtPosition,
        /* .pfnStartMode = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtEntity
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartModeWithTarget,
        /* .pfnStartMode = */ nullptr
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtPosition,
        /* .pfnStartMode = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtEntity
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtPosition,
        /* .pfnStartMode = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtEntity
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtPosition,
        /* .pfnStartMode = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtEntity
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtPosition,
        /* .pfnStartMode = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtEntity
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtPosition,
        /* .pfnStartMode = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtEntity
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtPosition,
        /* .pfnStartMode = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtEntity
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtPosition,
        /* .pfnStartMode = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtEntity
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_HandlePlayerDeath,
        /* .pfnStartMode = */ nullptr
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtPosition,
        /* .pfnStartMode = */ &D2Game::PLAYER::PlayerModes::PLRMODES_StartCastAtEntity
    },
    {
        /* .pfnMoveToLocation = */ &D2Game::PLAYER::PlayerModes::PLRMODES_SetMoveTargetPosition,
        /* .pfnStartMode = */ &D2Game::PLAYER::PlayerModes::PLRMODES_SetTargetAndStartPath
    }
};

D2ShrinesTableStrc OBJECTSHRINEFUNCTION = {
    /* .None = */ {
        /* .fpShrineHandler = */ nullptr,
        /* .eStat = */ -1,
        /* .nState = */ STATE_none
    },
    /* .Refill = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_RefillFunction,
        /* .eStat = */ -1,
        /* .nState = */ STATE_none
    },
    /* .HealthBoost = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_HealthBoostFunction,
        /* .eStat = */ -1,
        /* .nState = */ STATE_none
    },
    /* .ManaBoost = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_ManaBoostFunction,
        /* .eStat = */ -1,
        /* .nState = */ STATE_none
    },
    /* .HealthExchange = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_HealthExchangeFunction,
        /* .eStat = */ -1,
        /* .nState = */ STATE_none
    },
    /* .ManaExchange = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_ManaExchangeFunction,
        /* .eStat = */ -1,
        /* .nState = */ STATE_none
    },
    /* .ArmorBoost = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_StatBoostFunction,
        /* .eStat = */ UNITSTAT_skill_armor_percent,
        /* .nState = */ STATE_shrine_armor
    },
    /* .CombatBoost = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_CombatBoostFunction,
        /* .eStat = */ -1,
        /* .nState = */ STATE_shrine_combat
    },
    /* .ResistFireBoost = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_StatBoostFunction,
        /* .eStat = */ UNITSTAT_fireresist,
        /* .nState = */ STATE_shrine_resist_fire
    },
    /* .ResistColdBoost = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_StatBoostFunction,
        /* .eStat = */ UNITSTAT_coldresist,
        /* .nState = */ STATE_shrine_resist_cold
    },
    /* .ResistLightningBoost = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_StatBoostFunction,
        /* .eStat = */ UNITSTAT_lightresist,
        /* .nState = */ STATE_shrine_resist_lightning
    },
    /* .ResistPoisonBoost = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_StatBoostFunction,
        /* .eStat = */ UNITSTAT_poisonresist,
        /* .nState = */ STATE_shrine_resist_poison
    },
    /* .SkillBoost = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_SkillBoostFunction,
        /* .eStat = */ UNITSTAT_maxstamina,
        /* .nState = */ STATE_shrine_skill
    },
    /* .RechargeBoost = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_StatBoostFunction,
        /* .eStat = */ UNITSTAT_manarecoverybonus,
        /* .nState = */ STATE_shrine_mana_regen
    },
    /* .StaminaBoost = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_StaminaBoostFunction,
        /* .eStat = */ UNITSTAT_skill_staminapercent,
        /* .nState = */ STATE_shrine_stamina
    },
    /* .ExperienceBoost = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_StatBoostFunction,
        /* .eStat = */ UNITSTAT_item_addexperience,
        /* .nState = */ STATE_shrine_experience
    },
    /* .ShrineOfEnirhs = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_ShrineOfEnirhsFunction,
        /* .eStat = */ -1,
        /* .nState = */ STATE_none
    },
    /* .PortalShrine = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_PortalShrineFunction,
        /* .eStat = */ -1,
        /* .nState = */ STATE_none
    },
    /* .GemShrine = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_GemShrineFunction,
        /* .eStat = */ -1,
        /* .nState = */ STATE_none
    },
    /* .StormShrine = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_StormShrineFunction,
        /* .eStat = */ -1,
        /* .nState = */ STATE_none
    },
    /* .WarpingShrine = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_WarpingShrineFunction,
        /* .eStat = */ -1,
        /* .nState = */ STATE_none
    },
    /* .ExplodingShrine = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_ExplodingShrineFunction,
        /* .eStat = */ -1,
        /* .nState = */ STATE_none
    },
    /* .PoisonShrine = */ {
        /* .fpShrineHandler = */ &D2Game::Objects::ObjectsMode::Shrines_PoisonShrineFunction,
        /* .eStat = */ -1,
        /* .nState = */ STATE_none
    },
    /* .Terminator = */ {
        /* .fpShrineHandler = */ nullptr,
        /* .eStat = */ -1,
        /* .nState = */ STATE_none
    }
};

int gaMissileOffsets_LightningUniqueY[4] = { -0x1, 0x0, 0x1, 0x0 };

uint32_t gnAuraDamageScale_ManaAbsorb[3] = { 0xffffffff, 0x0, 0xffffffff };

uint8_t BYTE_ARRAY_006e3138[80] = {
    0xa,
    0x8,
    0x16,
    0x14,
    0x12,
    0x10,
    0xe,
    0xc,
    0x1b,
    0xe,
    0xf,
    0x3,
    0x63,
    0x7,
    0x15,
    0x16,
    0x1f,
    0x1a,
    0xc,
    0xd,
    0x2,
    0x63,
    0x6,
    0x13,
    0x14,
    0x1e,
    0x19,
    0xa,
    0xb,
    0x1,
    0x63,
    0x5,
    0x11,
    0x12,
    0x1d,
    0x18,
    0x8,
    0x9,
    0x0,
    0x63,
    0x4,
    0xf,
    0x10,
    0x1c,
    0x1f,
    0x16,
    0x17,
    0x7,
    0x63,
    0x3,
    0xd,
    0xe,
    0x1b,
    0x1e,
    0x14,
    0x7,
    0x6,
    0x63,
    0x2,
    0x1,
    0xc,
    0x1a,
    0x1d,
    0x12,
    0x13,
    0x5,
    0x63,
    0x1,
    0x9,
    0xa,
    0x19,
    0x1c,
    0x10,
    0x11,
    0x4,
    0x63,
    0x0,
    0x17,
    0x8,
    0x18
};

D2UnitIdToNameFunc PFN_UnitTypeCallbackTable[5] = { &D2Game::GAME::Server::_TableNullSub25, &D2Game::GAME::Server::MonsterIdToName, &D2Game::GAME::Server::ObjectIdToName, &D2Game::GAME::Server::ItemIdToName, &D2Game::GAME::Server::MissileIdToname };

int NPCINTRO_ListAct1[6] = { 0x94, 0x9a, 0x96, 0x93, 0x9b, 0x109 };

int NPCINTRO_ListAct2[11] = {
    0xaf,
    0xb0,
    0xb1,
    0xb2,
    0xca,
    0xc8,
    0xd2,
    0xc9,
    0xc6,
    0xc7,
    0xf4
};

int NPCINTRO_ListAct3[7] = { 0xf5, 0xfc, 0xfd, 0xfe, 0xff, 0x108, 0x129 };

int NPCINTRO_ListAct5[7] = { 0x208, 0x209, 0x1ff, 0x200, 0x201, 0x202, 0x203 };

D2PlayerModeNetMsgStrc gaPlayerModeNetMsgTable[20] = {
    {
        /* .pfnSend = */ &D2Game::PLAYER::PlayerMsg::SendPlayerStopAndAtributeUpdate,
        /* .nMoveModeByte = */ 0x8,
        /* .nObjModeByte = */ 0x8
    },
    {
        /* .pfnSend = */ &D2Game::PLAYER::PlayerMsg::PLRMSG_SendPlayerStopToOtherClient,
        /* .nMoveModeByte = */ 0x7,
        /* .nObjModeByte = */ 0x7
    },
    {
        /* .pfnSend = */ &D2Game::PLAYER::PlayerMsg::SendPlayerMoveOrObject,
        /* .nMoveModeByte = */ 0x1,
        /* .nObjModeByte = */ 0x0
    },
    {
        /* .pfnSend = */ &D2Game::PLAYER::PlayerMsg::SendPlayerMoveOrObject,
        /* .nMoveModeByte = */ 0x17,
        /* .nObjModeByte = */ 0x18
    },
    {
        /* .pfnSend = */ (pfnPlayerModeNetMsg)&D2Game::PLAYER::PlayerMsg::SendPlayerStop,
        /* .nMoveModeByte = */ 0x6,
        /* .nObjModeByte = */ 0x6
    },
    {
        /* .pfnSend = */ &D2Game::PLAYER::PlayerMsg::PLRMSG_SendPlayerStopToOtherClient,
        /* .nMoveModeByte = */ 0x7,
        /* .nObjModeByte = */ 0x7
    },
    {
        /* .pfnSend = */ &D2Game::PLAYER::PlayerMsg::SendPlayerMoveOrObject,
        /* .nMoveModeByte = */ 0x1,
        /* .nObjModeByte = */ 0x0
    },
    {
        /* .pfnSend = */ (pfnPlayerModeNetMsg)&D2Game::PLAYER::PlayerMsg::SendUnitCast0x4d,
        /* .nMoveModeByte = */ 0x15,
        /* .nObjModeByte = */ 0x16
    },
    {
        /* .pfnSend = */ (pfnPlayerModeNetMsg)&D2Game::PLAYER::PlayerMsg::SendUnitCast0x4d,
        /* .nMoveModeByte = */ 0x15,
        /* .nObjModeByte = */ 0x16
    },
    {
        /* .pfnSend = */ (pfnPlayerModeNetMsg)&D2Game::PLAYER::PlayerMsg::SendPlayerStop,
        /* .nMoveModeByte = */ 0x12,
        /* .nObjModeByte = */ 0x12
    },
    {
        /* .pfnSend = */ (pfnPlayerModeNetMsg)&D2Game::PLAYER::PlayerMsg::SendUnitCast0x4d,
        /* .nMoveModeByte = */ 0x15,
        /* .nObjModeByte = */ 0x16
    },
    {
        /* .pfnSend = */ (pfnPlayerModeNetMsg)&D2Game::PLAYER::PlayerMsg::SendUnitCast0x4d,
        /* .nMoveModeByte = */ 0x15,
        /* .nObjModeByte = */ 0x16
    },
    {
        /* .pfnSend = */ (pfnPlayerModeNetMsg)&D2Game::PLAYER::PlayerMsg::SendUnitCast0x4d,
        /* .nMoveModeByte = */ 0x15,
        /* .nObjModeByte = */ 0x16
    },
    {
        /* .pfnSend = */ (pfnPlayerModeNetMsg)&D2Game::PLAYER::PlayerMsg::SendUnitCast0x4d,
        /* .nMoveModeByte = */ 0x15,
        /* .nObjModeByte = */ 0x16
    },
    {
        /* .pfnSend = */ (pfnPlayerModeNetMsg)&D2Game::PLAYER::PlayerMsg::SendUnitCast0x4d,
        /* .nMoveModeByte = */ 0x15,
        /* .nObjModeByte = */ 0x16
    },
    {
        /* .pfnSend = */ (pfnPlayerModeNetMsg)&D2Game::PLAYER::PlayerMsg::SendUnitCast0x4d,
        /* .nMoveModeByte = */ 0x15,
        /* .nObjModeByte = */ 0x16
    },
    {
        /* .pfnSend = */ (pfnPlayerModeNetMsg)&D2Game::PLAYER::PlayerMsg::SendUnitCast0x4d,
        /* .nMoveModeByte = */ 0x15,
        /* .nObjModeByte = */ 0x16
    },
    {
        /* .pfnSend = */ (pfnPlayerModeNetMsg)&D2Game::PLAYER::PlayerMsg::SendPlayerStop,
        /* .nMoveModeByte = */ 0x9,
        /* .nObjModeByte = */ 0x9
    },
    {
        /* .pfnSend = */ (pfnPlayerModeNetMsg)&D2Game::PLAYER::PlayerMsg::SendUnitCast0x4d,
        /* .nMoveModeByte = */ 0x15,
        /* .nObjModeByte = */ 0x16
    },
    {
        /* .pfnSend = */ &D2Game::PLAYER::PlayerMsg::SendPlayerMove,
        /* .nMoveModeByte = */ 0x14,
        /* .nObjModeByte = */ 0x14
    }
};

int gnDirectionXOffsets[8] = { -0x1, 0x0, 0x1, -0x1, 0x1, -0x1, 0x0, 0x1 };

int gnDirectionYOffsets[8] = { -0x1, -0x1, -0x1, 0x0, 0x0, 0x1, 0x1, 0x1 };

D2ObjectPopulateFnFunc OBJECTSPOPULATEFN[10] = {
    nullptr,
    (D2ObjectPopulateFnFunc)&D2Game::Objects::Objects_PopulateFn1,
    (D2ObjectPopulateFnFunc)&D2Game::Objects::Objects_PopulateFn2,
    (D2ObjectPopulateFnFunc)&D2Game::Objects::Objects_PopulateFn3,
    (D2ObjectPopulateFnFunc)&D2Game::Objects::Objects_PopulateFn4,
    (D2ObjectPopulateFnFunc)&D2Game::Objects::Objects_PopulateFn5,
    (D2ObjectPopulateFnFunc)&D2Game::Objects::Objects_PopulateFn6,
    (D2ObjectPopulateFnFunc)&D2Game::Objects::Objects_PopulateFn7,
    (D2ObjectPopulateFnFunc)&D2Game::Objects::Objects_PopulateFn8,
    (D2ObjectPopulateFnFunc)&D2Game::Objects::Objects_PopulateFn9
};

int gaObjectSpawnChanceTbl[5] = { 0x4, 0x9, 0x34, 0x5e, 0x5f };

D2ObjectPopulateEntryStrc gaObjectPopulateTable[7] = {
    {
        /* .nEnabled = */ 0x0,
        /* .pfnPopulate = */ nullptr
    },
    {
        /* .nEnabled = */ 0x1,
        /* .pfnPopulate = */ &D2Game::Objects::OBJECT_AlwaysReturnOne
    },
    {
        /* .nEnabled = */ 0x1,
        /* .pfnPopulate = */ &D2Game::Objects::OBJECT_PopulateGridObjects
    },
    {
        /* .nEnabled = */ 0x0,
        /* .pfnPopulate = */ nullptr
    },
    {
        /* .nEnabled = */ 0x1,
        /* .pfnPopulate = */ &D2Game::Objects::OBJECT_PopulateGridItems
    },
    {
        /* .nEnabled = */ 0x1,
        /* .pfnPopulate = */ &D2Game::Objects::ArmorWeapon::RollArmorStand
    },
    {
        /* .nEnabled = */ 0x1,
        /* .pfnPopulate = */ &D2Game::Objects::ArmorWeapon::RollWeaponRack
    }
};

D2ObjectSpawnOffsetGroupStrc gaObjectSpawnOffsetTables[4] = {
    {
        /* .pOffsets = */ gaObjectSpawnOffsetGroup0,
        /* .nCount = */ 0x0
    },
    {
        /* .pOffsets = */ (int*)&gaObjectSpawnOffsetGroup0[13],
        /* .nCount = */ 0x0
    },
    {
        /* .pOffsets = */ (int*)&gaObjectSpawnOffsetGroup0[24],
        /* .nCount = */ 0x0
    },
    {
        /* .pOffsets = */ (int*)&gaObjectSpawnOffsetGroup0[35],
        /* .nCount = */ 0x0
    }
};

D2SkillSrvStFunc SKILLSRVSTFUNCS[91] = {
    nullptr,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillsServer::SKILLS_SrvStFn01_Attack,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillsServer::SKILLS_SrvStFn02_Kick,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillsServer::SKILLS_SrvStFn03_Unsummon,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillAma::SKILLAMA_SrvStFn04_ArrowAttack,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillAma::SKILLAMA_SrvStFn05_Jab,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillAma::SKILLAMA_SrvStFn06_PowerStrike,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillAma::SKILLAMA_SrvStFn07_Impale,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillAma::SKILLAMA_SrvStFn08_Strafe,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillAma::SKILLAMA_SrvStFn09_Fend,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillAma::SKILLAMA_SrvStFn10_LightningStrike,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillSor::SKILLSOR_SrvStFn11_InfernoChannel,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillSor::SKILLSOR_SrvStFn12_TargetInAuraRange,
    &D2Game::SKILLS::SkillSor::SKILLSOR_SrvStFn13_ThunderStorm,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillSor::SKILLSOR_SrvStFn14_Hydra,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillNec::Skills_SrvStFunc_15_IsConsumableCorpseOutsideTown,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillNec::Skills_SrvStFunc_16_ApplyHitAndDamage,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillNec::Skills_SrvStFunc_17_IsSelectableCorpseOutsideTown,
    &D2Game::SKILLS::SkillNec::Skills_SrvStFunc_18_AlwaysAllow,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillNec::Skills_SrvStFunc_19_IsTargetOutsideTown,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillNec::Skills_SrvStFunc_20_IsGroundItemForIronGolem,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillNec::Skills_SrvStFunc_21_IsRevivableCorpse,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillAss::SKILLASS_SrvStFn22_PsychicHammer,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillAss::SKILLASS_SrvStFn23_MartialArtsCharge,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillAss::SKILLASS_SrvStFn24_DragonTalon,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillAss::SKILLASS_SrvStFn25_DragonClaw,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillAss::SKILLASS_SrvStFn26_BladeFury,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillAss::SKILLASS_SrvStFn27_DragonTail,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillAss::SKILLASS_SrvStFn28_BladeShield,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillPal::SKILLPAL_SrvStFn29_Sacrifice,
    nullptr,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillPal::SKILPAL_SrvStFn31_Charge,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillBar::SKILLBAR_SrvStFn32_StrikeWithAuraState,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillBar::SKILLBAR_SrvStFn33_TargetRevivableCorpse,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillBar::SKILLBAR_SrvStFn34_FindItem,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillPal::SKILPAL_SrvStFn35_Vengeance,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillPal::SKILPAL_SrvStFn36_HolyShield,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillAma::SKILLAMA_SrvStFn37_MultiStrike,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillBar::SKILLBAR_SrvStFn38_Whirlwind,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillBar::SKILLBAR_SrvStFn39_Berserk,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillBar::SKILLBAR_SrvStFn40_Leap,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillBar::SKILLBAR_SrvStFn41_LeapAttack,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvStFn42_FireHit,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvStFn43_MaggotEgg,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvStFn44_MaggotUp,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvStFn45_MaggotDown,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvStFn46_AndrialSpray,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvStFn47_Jump,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvStFn48_SwarmMove,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvStFn49_NestSpawn,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvStFn50_QuickStrike,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvStFn51_Submerge,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvStFn52_Emerge,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvStFn53_MonInferno,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvStFn54_DiabRun,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvStFn55_Mosquito,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillDruid::SKILLDRUID_SrvStFn56_FeralRageMaul,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillDruid::SKILLDRUID_SrvStFn57_Rabies,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillDruid::SKILLDRUID_SrvStFn58_FireClaws,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillEMonst::SKILLEMONST_SrvStFn59_ImpInferno,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillEMonst::SKILLEMONST_SrvStFn60_SuckBlood,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillEMonst::SKILLEMONST_SrvStFn61_SelfResurrect,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillEMonst::SKILLEMONST_SrvStFn62_MinionSpawner,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillEMonst::SKILLEMONST_SrvStFn63_CorpseCycler,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvStFn64_MonFrenzy,
    (D2SkillSrvStFunc)&D2Game::SKILLS::SkillsServer::SKILLS_SrvStFn65_Throw,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
};

D2SkillSrvDoFunc SKILLSRVDOFUNCS[191] = {
    nullptr,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillsServer::Skills_SrvDoFunc_001_ShootArrow,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillsServer::Skills_SrvDoFunc_002_GenericMeleeHit,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillsServer::Skills_SrvDoFunc_003_ThrowWeaponLeftHand,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillsServer::Skills_SrvDoFunc_004_RemovePetBySkillParam,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillsServer::Skills_SrvDoFunc_005_ThrowWeaponRightHand,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAma::Skills_SrvDoFunc_006_PhoenixStrikeAreaBolt,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAma::Skills_SrvDoFunc_007_Jab,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAma::Skills_SrvDoFunc_008_MultipleShot,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillBar::Skills_SrvDoFunc_009_FrenzyMeleeHit,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAma::Skills_SrvDoFunc_010_GuidedArrowLaunch,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAma::Skills_SrvDoFunc_011_ChargedStrike,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAma::Skills_SrvDoFunc_012_StrafeContinue,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAma::Skills_SrvDoFunc_013_MultiHitAttack,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAma::Skills_SrvDoFunc_014_LightningStrike,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAma::Skills_SrvDoFunc_015_SummonDecoy,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAma::Skills_SrvDoFunc_016_SummonValkyrie,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillSor::Skills_SrvDoFunc_017_ChargedBolt,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillSor::Skills_SrvDoFunc_018_Armor,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillSor::Skills_SrvDoFunc_019_Inferno,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillSor::Skills_SrvDoFunc_020_Static,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillSor::Skills_SrvDoFunc_021_Telekenis,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillSor::Skills_SrvDoFunc_022_Nova_FrostNova,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillSor::Skills_SrvDoFunc_023_Blaze_EnergyShield,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillSor::Skills_SrvDoFunc_024_FireWall,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillSor::Skills_SrvDoFunc_025_Enchant,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillSor::Skills_SrvDoFunc_026_ChainLighting,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillSor::Skills_SrvDoFunc_027_Teleport,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillSor::Skills_SrvDoFunc_028_Meteor_Blizzard,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillSor::Skills_SrvDoFunc_029_ThunderStorm,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillNec::Skills_SrvDoFunc_030_CastCurseAoE,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillNec::Skills_SrvDoFunc_031_RaiseSkeletonFromCorpse,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillNec::Skills_SrvDoFunc_032_ApplyDirectDamage,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_033_PsychicHammer,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_034_ChargeUpStackMelee,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_035_ElementalChargeRelease,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_036_ChargeRelease_MissileRing,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_037_ChargeRelease_MultiElementScatter,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_038_DragonTail_KickAoE,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_039_ChargeRelease_CircleSpawn,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_040_ChargeRelease_SingleMissile,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_041_BladeFury,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_042_DragonTalon,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_043_ChargeRelease_ScatterMissiles,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_044_SummonBladeSentinel,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_045_SummonTrapSentry,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_046_DragonClaw,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_047_CloakOfShadows,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_048_BladeFury,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_049_SummonShadowClone,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_050_DragonTail_FireExplosion,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_051_MindBlast,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_052_DragonFlight,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_053_Venom_BladeShield_AreaPulse,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_054_BladeShield_Activate,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillNec::Skills_SrvDoFunc_055_CorpseExplosion,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillNec::Skills_SrvDoFunc_056_SummonGolem,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillNec::Skills_SrvDoFunc_057_IronGolem,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillNec::Skills_SrvDoFunc_058_ReviveCorpseCheck,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillNec::Skills_SrvDoFunc_059_CastCorpseSkill,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillNec::Skills_SrvDoFunc_060_SummonBoneWall,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillNec::Skills_SrvDoFunc_061_CastConvertAoE,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillNec::Skills_SrvDoFunc_062_BonePrison,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillNec::Skills_SrvDoFunc_063_PoisonExplosion,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillPal::Skills_SrvDoFunc_064_Sacrifice,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillPal::Skills_SrvDoFunc_065_Prayer,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillPal::Skills_SrvDoFunc_066_Conviction,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillPal::Skills_SrvDoFunc_067_Charge,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillBar::Skills_SrvDoFunc_068_WarCry,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillBar::Skills_SrvDoFunc_069_FindPotion,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillBar::Skills_SrvDoFunc_070_DoubleSwing,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillBar::Skills_SrvDoFunc_071_IronMaiden_GenericCurse,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillBar::Skills_SrvDoFunc_072_FindItem,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillPal::Skills_SrvDoFunc_073_BlessedHammer,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillBar::Skills_SrvDoFunc_074_DoubleThrow,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillBar::Skills_SrvDoFunc_075_GrimWard,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillBar::Skills_SrvDoFunc_076_Whirlwind,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillBar::Skills_SrvDoFunc_077_Leap,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillBar::Skills_SrvDoFunc_078_LeapAttack,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillPal::Skills_SrvDoFunc_079_Conversion,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillPal::Skills_SrvDoFunc_080_FistOfTheHeavens,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillPal::Skills_SrvDoFunc_081_HolyFreeze,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillPal::Skills_SrvDoFunc_082_Redemption,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_083_MonsterMeleeAttack,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_084_SpawnMinionsAndSuicide,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_085_FireUpgradedMissile,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_086_SelfHeal,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_087_SpawnBehindTarget,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_088_FireMissileFromBodyPart,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_089_ChargeLeapAttack,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_090_SetAnimFrameFromCalc,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_091_SpawnMinionAtCoords,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::SKILLMONST_SrvDoFunc092_MeleeHitThenMissile,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_093_FireLeadingMissile,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_094_ResetAnimFrame,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_095_SpawnTrapMissile,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_096_HealTarget,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_097_ResurrectDeadMonster,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_098_TeleportToStoredPosition,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_099_FireMissileRing8Dir,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_100_FreezingMeleeAttack,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_101_FireDirectionalMissile,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_102_FireRandomMultiMissile,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_103_ChargeAndMeleeStrike,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_104_SpawnPredefinedAtTarget,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_105_FireParallelMissileVolley,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_106_FireMissileRingOnTarget,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_107_LeechMeleeMultiHit,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_108_DevourMinionForHP,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_109_MonsterFrenzyAttack,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_110_FireArrowModMissile,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_111_ApplyFetishAura,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_112_RandomCurse,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillItem::Skills_SrvDoFunc_113_UseScrollOrBook,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillDruid::Skills_SrvDoFunc_114_SummonRaven,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillDruid::Skills_SrvDoFunc_115_SummonPoisonCreeper,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillDruid::Skills_SrvDoFunc_116_Werewolf,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillDruid::Skills_SrvDoFunc_117_Firestorm,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillDruid::Skills_SrvDoFunc_118_Twister,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillDruid::Skills_SrvDoFunc_119_SummonDireWolf,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillDruid::Skills_SrvDoFunc_120_FeralRage,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillDruid::Skills_SrvDoFunc_121_Rabies,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillDruid::Skills_SrvDoFunc_122_Hunger,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillDruid::Skills_SrvDoFunc_123_Tornado,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillDruid::Skills_SrvDoFunc_124_Armageddon,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_125_CatapultFireBomb,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_126_ImpInferno,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_127_SuckBlood,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_128_MonsterCreateMinion,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_129_AttachOrDetachFromHost,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_130_SpawnSubMissiles,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_131_ConditionalTransformOrBuff,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_132_FireClassUpgradedMissile,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_133_SetDeathSpawnState,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_134_AreaExplosionAttack,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_135_SpawnMinionFromParams,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_136_FireSpeedScaledMissile,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_137_CorpseConsumptionAura,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_138_FirePerpendicularMissileLine,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_139_FireOrthogonalMissile,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_140_BaalTentacle,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_141_BaalCorpseExplosionWave,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_142_BladeShield_SpinDamage,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillAss::Skills_SrvDoFunc_143_ChargeRelease_GroundStrike,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillSor::Skills_SrvDoFunc_144_Hydra,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillDruid::Skills_SrvDoFunc_145_Hurricane,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillDruid::Skills_SrvDoFunc_146_CycloneArmor,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillEMonst::Skills_SrvDoFunc_147_ReturnToOwner,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_148_FireMissileBodyPart10,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_149_FireMissileBodyPart11,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillPal::Skills_SrvDoFunc_150_Smite,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillSor::Skills_SrvDoFunc_151_FireDirectionalMissile,
    (D2SkillSrvDoFunc)&D2Game::SKILLS::SkillMonst::Skills_SrvDoFunc_152_SpawnTrapMissileVariant,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
};

int gaNPCSpokenBitIndexMap[35][2] = {
    { -0x1, 0x0 },
    { 0x93, 0x1 },
    { 0x94, 0x2 },
    { 0x96, 0x3 },
    { 0x9b, 0x4 },
    { 0x9a, 0x5 },
    { 0x109, 0x6 },
    { 0xaf, 0x7 },
    { 0xb0, 0x8 },
    { 0xb1, 0x9 },
    { 0xb2, 0xa },
    { 0xca, 0xb },
    { 0xc8, 0xc },
    { 0xd2, 0xd },
    { 0xc9, 0xe },
    { 0xc6, 0xf },
    { 0xc7, 0x10 },
    { 0xf4, 0x11 },
    { 0xf5, 0x12 },
    { 0xf6, 0x13 },
    { 0xfb, 0x14 },
    { 0xfc, 0x15 },
    { 0xfd, 0x16 },
    { 0xfe, 0x17 },
    { 0xff, 0x18 },
    { 0x100, 0x19 },
    { 0x101, 0x1a },
    { 0x108, 0x1b },
    { 0x129, 0x1c },
    { 0x1ff, 0x1d },
    { 0x200, 0x1e },
    { 0x201, 0x1f },
    { 0x202, 0x20 },
    { 0x203, 0x21 },
    { 0x208, 0x22 }
};

PFN_ObjectOperateCallback gapObjectOperateCallbacks[10] = {
    nullptr,
    &D2Game::Objects::ObjectsMode::OBJMODE_SpawnSiegeMonsterA,
    &D2Game::Objects::ObjectsMode::OBJMODE_SpawnSiegeMonsterB,
    &D2Game::Objects::ObjectsMode::OBJMODE_SpawnSiegeMonsterC,
    &D2Game::Objects::ObjectsMode::OBJMODE_SpawnSiegeMonsterD,
    &D2Game::Objects::ObjectsMode::OBJMODE_SpawnCompanionChests,
    &D2Game::Objects::ObjectsMode::OBJMODE_SpawnSiegeMonsterB,
    &D2Game::Objects::ObjectsMode::OBJMODE_SpawnCompanionChests,
    &D2Game::Objects::ObjectsMode::OBJMODE_SpawnRandomMonsters,
    &D2Game::Objects::ObjectsMode::OBJMODE_SpawnRandomMonsters
};

D2ObjectOperateFnFunc OBJECTSOPERATEFN[101] = {
    nullptr,
    &D2Game::Objects::ObjectsMode::OBJOP_OpenChestSpawnMonster,
    &D2Game::Objects::ObjectsMode::OBJOP_ActivateShrine,
    &D2Game::Objects::ObjectsMode::OBJOP_OpenChestNoMonster,
    &D2Game::Objects::ObjectsMode::OBJOP_OpenSparklyChest,
    &D2Game::Objects::ObjectsMode::OBJOP_OpenTrapChestSkillTrigger,
    &D2Game::Quests::QUESTS::A1Q5::OBJOP_A1Q5_ActivateCairnStone,
    &D2Game::Objects::ObjectsMode::OBJOP_DetonateExplosiveBarrel,
    &D2Game::Objects::ObjectsMode::OBJOP_ToggleDoor,
    &D2Game::Quests::QUESTS::A1Q4::OBJOP_A1Q4_ActivateHoradricMalusSmith,
    &D2Game::Quests::QUESTS::A1Q4::OBJOP_A1Q4_ActivateInifussTree,
    &D2Game::Objects::ObjectsMode::OBJOP_ActivateNoOp,
    &D2Game::Quests::QUESTS::A1Q4::OBJOP_A1Q4_UseScrollOfInifuss,
    &D2Game::Objects::ObjectsMode::OBJOP_ActivateSimple,
    &D2Game::Objects::ObjectsMode::OBJOP_OpenLockedChest,
    &D2Game::Objects::ObjectsMode::Objects_OperateFn15_Portal,
    &D2Game::Objects::ObjectsMode::OBJOP_UseStairway,
    &D2Game::Objects::ObjectsMode::OBJOP_OpenHoradricCube,
    &D2Game::Objects::ObjectsMode::OBJOP_DestroyDestructible,
    &D2Game::Objects::ObjectsMode::OBJOP_SpawnExceptionalItemDrop,
    &D2Game::Objects::ObjectsMode::OBJOP_SpawnNormalItemDrop,
    &D2Game::Quests::QUESTS::A1Q3::OBJOP_A1Q3_DenOfEvil_CheckCompletion,
    &D2Game::Objects::ObjectsMode::OBJOP_ActivateHealingWell,
    &D2Game::Objects::ObjectsMode::OBJOP_ActivateWaypoint,
    &D2Game::Quests::QUESTS::A2Q3::OBJOP_A2Q3_ActivateHoradricStaffAltar,
    &D2Game::Quests::QUESTS::A2Q7::OBJOP_A2Q7_OpenArcaneNpcTrade,
    &D2Game::Objects::ObjectsMode::OBJOP_SpawnQuestItemReward,
    &D2Game::Objects::ObjectsMode::OBJOP_RevealAutomapArea,
    &D2Game::Quests::QUESTS::A3Q1::OBJOP_A3Q1_KhalimsRelicAltar,
    &D2Game::Objects::ObjectsMode::OBJOP_OpenBreakableContainer,
    &D2Game::Objects::ObjectsMode::OBJOP_ExplodingTrap,
    &D2Game::Quests::QUESTS::A3Q3::OBJOP_A3Q5_NihlathakPortalTrigger,
    &D2Game::PLAYER::PlayerTrade::Objects_OperateFn32_OpenStash,
    &D2Game::Objects::ObjectsMode::OBJOP_SpawnRewardItem,
    &D2Game::Objects::ObjectsMode::OBJOP_A2Q2_ArcaneGateLevelTransition,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &D2Game::Quests::QUESTS::A2Q2::OBJOP_A2Q2_ArcaneSanctuaryPortalAndDrop1,
    &D2Game::Quests::QUESTS::A2Q2::OBJOP_A2Q2_ArcaneSanctuaryPortalAndDrop2,
    &D2Game::Quests::QUESTS::A2Q2::OBJOP_A2Q2_ArcaneSanctuaryPortalAndDrop3,
    &D2Game::Quests::QUESTS::A2Q4::OBJOP_A2Q4_StaffOfKingsAltar,
    &D2Game::Objects::ObjectsMode::OBJOP_ActivatePortalObject,
    &D2Game::Quests::QUESTS::A3Q2::OBJOP_UseStairDirect,
    &D2Game::Quests::QUESTS::A3Q2::OBJOP_A3Q2_KhalimRelicPedestal,
    &D2Game::Objects::ObjectsMode::Objects_OperateFn46_PortalToAct4,
    &D2Game::Objects::ObjectsMode::OBJOP_UseWaygate,
    &D2Game::Objects::ObjectsMode::OBJOP_OpenUnlockedChest,
    &D2Game::Quests::QUESTS::A4Q3::OBJOP_A4Q3_HellforgeSmash,
    &D2Game::Objects::ObjectsMode::OBJOP_UseStairAlias,
    &D2Game::Objects::ObjectsMode::OBJOP_TimedDestructible,
    &D2Game::Quests::QUESTS::A4Q2::OBJOP_A4Q2_DiabloSealActivateKillChaos,
    &D2Game::Quests::QUESTS::A3Q5::OBJOP_A3Q5_NihlathakAltarLaunchOrb,
    &D2Game::Quests::QUESTS::OBJOP_A4Q2_DiabloSealCreateGlow1,
    &D2Game::Quests::QUESTS::OBJOP_A4Q2_DiabloSealCreateGlow2,
    &D2Game::Quests::QUESTS::OBJOP_A4Q2_DiabloSealCreateGlow3,
    &D2Game::Quests::QUESTS::A3Q2::OBJOP_A3Q2_KhalimsRelicPortalDrop1,
    &D2Game::Quests::QUESTS::A3Q2::OBJOP_A3Q2_KhalimsRelicPortalDrop2,
    &D2Game::Quests::QUESTS::A3Q2::OBJOP_A3Q2_KhalimsRelicPortalDrop3,
    nullptr,
    &D2Game::Objects::ObjectsMode::OBJOP_OpenTimedDoor,
    &D2Game::Quests::QUESTS::A5Q5::OBJOP_A5Q5_AncientsTriggerSound1,
    &D2Game::Quests::QUESTS::A5Q5::OBJOP_A5Q5_AncientsTriggerSound2,
    &D2Game::Quests::QUESTS::A5Q5::OBJOP_A5Q5_AncientsTriggerSound3,
    &D2Game::Quests::QUESTS::A5Q5::OBJOP_A5Q5_AncientsAltarActivate,
    &D2Game::Quests::QUESTS::A5Q5::OBJOP_A5Q5_WorldstonePortalActivate,
    &D2Game::Quests::QUESTS::A5Q3::OBJOP_A5Q3_RescueAnyaFromPortal,
    &D2Game::Objects::ObjectsMode::OBJOP_OpenBossChestSpawnUniques,
    &D2Game::Quests::QUESTS::A5Q5::OBJOP_A5Q5_AncientsQuestStateQuery,
    &D2Game::Quests::QUESTS::A5Q6::OBJOP_A5Q6_WorldstoneLevelTransition,
    &D2Game::Quests::QUESTS::A5Q5::OBJOP_A5Q5_WorldstoneStairPortal,
    &D2Game::Quests::QUESTS::A5Q6::OBJOP_A5Q6_TyraelPortalToEnd,
    &D2Game::Quests::QUESTS::A4Q3::OBJOP_A4Q2_PandemoniumFortressGate,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
};

D2MonsterUModHandlerRowStrc g_MonsterUModHandlerTable[43] = {
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ &D2Game::Monsters::MONSTER_OnDeathAmplifyDamageAura,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ &D2Game::Monsters::MONSTER_OnDeathScheduleDelayed,
        /* .pfnHandler2 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_CorpseExplode,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_ScheduleDeathEvent,
        /* .pfnHandler2 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_DeathPoisonCloud,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ (fpMonsterUModHandler)&D2Game::Monsters::UMOD_SetLevelAndAttackRating,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_OnDeathKillOwnerAndMinions,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ &D2Game::Monsters::MONSTER_ScheduleEventIfRunning,
        /* .pfnHandler2 = */ &D2Game::Monsters::MONSTER_LightningUniqueDeathBolts,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ &D2Game::Monsters::MONSTER_LightningDeathIfNotRunning,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_ScheduleDeathEvent,
        /* .pfnHandler2 = */ &D2Game::Monsters::MONSTER_DeathMissileRing,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ (fpMonsterUModHandler)&D2Game::Monsters::UMOD_AddBaseDamageBonus,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_ScaleMissileDamageByOwner
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ &D2Game::MONSTER_ScheduleDeathIfRunningOrDead,
        /* .pfnHandler2 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_BugLightningDeathBolts,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_HandleMinionDeath,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_DispatchSpecialDeath,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_QueenPoisonCloudDeath,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ &D2Game::Monsters::MONSTER_StealPotionFromBelt,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ (fpMonsterUModHandler)&D2Game::Monsters::UMOD_SetRandomElementalDamage,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ (fpMonsterUModHandler)&D2Game::Monsters::UMOD_SetRandomElementalForMissile
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_MissileSplitOnHit
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_ScheduleDeathEvent,
        /* .pfnHandler2 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_CorpseExplodeFixed,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_ScheduleDeathEvent,
        /* .pfnHandler2 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_AoEPhysicalDamage,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_HandleModeTransition,
        /* .pfnHandler2 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_SuicideExplosion,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_OnDeathTryScheduleRevive,
        /* .pfnHandler2 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_SelfResurrect,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ &D2Game::Monsters::FUN_005a3a80,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ &D2Game::Monsters::FUN_005a4200,
        /* .pfnHandler2 = */ nullptr,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ nullptr,
        /* .pfnHandler2 = */ &D2Game::Monsters::FUN_005a4230,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    },
    {
        /* .pfnHandler0 = */ nullptr,
        /* .pfnHandler1 = */ (fpMonsterUModHandler)&D2Game::Monsters::MONSTER_ScheduleDeathEvent,
        /* .pfnHandler2 = */ &D2Game::Monsters::MONSTER_ShadowDeathNova,
        /* .pfnHandler3 = */ nullptr,
        /* .pfnHandler4 = */ nullptr,
        /* .pfnHandlerInit = */ nullptr
    }
};

D2MissileSrvDoFuncData gaMissileSrvDoFuncTable[9] = {
    {
        /* .pFunction = */ nullptr,
        /* .nFlags = */ 0x0
    },
    {
        /* .pFunction = */ (fpMissileSrvDoFuncData)&D2Game::MISSILES::MissilesMode::SrvDoFunc::fpMissileSrvDoFuncData_PlayerOrAllyMonster,
        /* .nFlags = */ 0x84
    },
    {
        /* .pFunction = */ (fpMissileSrvDoFuncData)&D2Game::MISSILES::MissilesMode::SrvDoFunc::fpMissileSrvDoFuncData_MonsterOnly,
        /* .nFlags = */ 0x104
    },
    {
        /* .pFunction = */ (fpMissileSrvDoFuncData)&D2Game::MISSILES::MissilesMode::SrvDoFunc::fpMissileSrvDoFuncData_PlayerOrMonster,
        /* .nFlags = */ 0x184
    },
    {
        /* .pFunction = */ nullptr,
        /* .nFlags = */ 0x0
    },
    {
        /* .pFunction = */ (fpMissileSrvDoFuncData)&D2Game::MISSILES::MissilesMode::SrvDoFunc::fpMissileSrvDoFuncData_MonsterOnly,
        /* .nFlags = */ 0x104
    },
    {
        /* .pFunction = */ nullptr,
        /* .nFlags = */ 0x4
    },
    {
        /* .pFunction = */ (fpMissileSrvDoFuncData)&D2Game::MISSILES::MissilesMode::SrvDoFunc::fpMissileSrvDoFuncData_MissileFlagCheck,
        /* .nFlags = */ 0x40
    },
    {
        /* .pFunction = */ (fpMissileSrvDoFuncData)&D2Game::MISSILES::MissilesMode::SrvDoFunc::fpMissileSrvDoFuncData_PlayerOrMonster,
        /* .nFlags = */ 0x185
    }
};

D2MissileSrvHitFunc MISSILESSRVHITFUNCS[71] = {
    nullptr,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_AreaElementalDamageExplosion,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnRadialSubMissiles,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_WallHitDelegateToAreaDamage,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnHitSubMissilesAndHit,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnSpreadSubMissiles,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnMonsterAtHit,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_HealTarget,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_BlockSelfHitByState,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_AreaDamageWithSpawnPattern,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_PierceOrExplodeOnWall,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnHitSubMissiles,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_ChainPierceWithBounce,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_AreaDamageWithDurationMod,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_AreaDamageAndRadialBurst,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnStationarySubMissile,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_ApplyAuraStateToTarget,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_ApplyTerrorToMonster,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_ApplyWarCryBuff,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_ApplyTimedAuraState,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnSubMissileAtFrameInArea,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_ApplyTimedAuraStateFiltered,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnSubMissileInvertFrameInArea,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_DispatchSrvDoFunc,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_AreaPhysicalDamageExplosion,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnDirectionalSubMissiles,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnStationarySubMissileAtPos,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_NoOp,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_ApplyTerrorNearMinion,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnSpreadSubMissilesOnFirstFrame,
    nullptr,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_LeechHpToOwner,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnPortalOnWallHit,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SetRoomPortalFlag,
    nullptr,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_ActivateObjectOnWallHit,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnSubMissileAtWallHit,
    (D2MissileSrvHitFunc)&D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_AlwaysPierce,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnMissileStarPattern,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnRandomMonsterAtHit,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_CastScatterMissiles,
    nullptr,
    nullptr,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_HealTargetRandom,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_AreaSplashDamage,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnFixedMissileStar,
    nullptr,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_AreaDamageLargeMonstersAndRadialBurst,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnSubMissileAtDirectionPoint,
    nullptr,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_BlockHitUntilFrame,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnUpToThreeSubMissiles,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnEightDirectionSubMissiles,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_ApplyDruidAuraWithMissile,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnMonsterFromSkillParam,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_DrainTargetManaPercent,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_AreaDamageAndSpawnSubMissile,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnTyraelAndOpenPortal,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnRandomOffsetSubMissile,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvHitFunc_SpawnDualRadialSubMissiles,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
};

D2MissileSrvDmgFunc MISSILESSRVDMGFUNCS[31] = {
    nullptr,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvDmgFunc_PhysToElementalByCalc1,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvDmgFunc_FreezeLengthFromColdLengthPct,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvDmgFunc_RollChanceFlagBlessedAim,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvDmgFunc_ConvertColdLengthToFreezeLength,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvDmgFunc_ElementalBonusVsUndeadDemon,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvDmgFunc_SetTargetNotControlled,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvDmgFunc_SetStunLengthFromParam1,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvDmgFunc_ApplyProgOverlayToTarget,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvDmgFunc_SetStunLengthFromSkillParam,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvDmgFunc_CopyColdLengthToFreezeLength,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvDmgFunc_SynergyCappedPoisonLength,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvDmgFunc_RecalcElementalWithClear,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvDmgFunc_ScaleByDamagePctThenElemBonus,
    &D2Game::MISSILES::MissilesMode::Missiles_SrvDmgFunc_RollMonsterSizeKnockbackChance,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
};

D2ItemSpellStrc ITEMSPELLFUNCS[31] = {
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ &D2Game::SKILLS::SkillItem::SKILLITEM_ItemSpellInit_UseStackable,
        /* .pSpellDestroy = */ &D2Game::SKILLS::SkillItem::SKILLITEM_IdentifyScrollSpell
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ &D2Game::SKILLS::SkillItem::SKILLITEM_TownPortalScrollSpell
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ &D2Game::SKILLS::SkillItem::ITEM_ApplyConsumableEffects
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ &D2Game::SKILLS::SkillItem::ITEM_ApplyConsumableEffectsSimple
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ &D2Game::SKILLS::SkillItem::ITEM_ApplyPercentRestoration
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ &D2Game::SKILLS::SkillItem::ITEM_RefreshBuffStates
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ &D2Game::SKILLS::SkillItem::SKILLITEM_PersonalizeItemSpell
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ &D2Game::SKILLS::SkillItem::SKILLITEM_ApplyRejuvenationPotionEffect
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ &D2Game::SKILLS::SkillItem::ITEM_ApplyTimedBuffStats
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ &D2Game::SKILLS::SkillItem::ITEM_CastFireballOnTarget
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ &D2Game::SKILLS::SkillItem::SKILLITEM_CastExplosivePotionSkill
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    },
    {
        /* .pSpellInit = */ nullptr,
        /* .pSpellDestroy = */ nullptr
    }
};

// also labelled: lpCritical_GenerateToken, lpCriticalSection_00882d18
_RTL_CRITICAL_SECTION gQServerGameListCs = {
    /* .DebugInfo = */ nullptr,
    /* .LockCount = */ 0,
    /* .RecursionCount = */ 0,
    /* .OwningThread = */ nullptr,
    /* .LockSemaphore = */ nullptr,
    /* .SpinCount = */ 0
};

SGAMEDATA * gaQServerGameByToken[1025] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
};

D2NpcItemTablesStrc gaNpcItemTables[17] = {
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    },
    {
        /* .pTradeItems = */ nullptr,
        /* .nTradeCount = */ 0,
        /* .pQuestItems = */ nullptr,
        /* .nQuestCount = */ 0
    }
};

uint8_t gbaNpcItemTableBuilt[17] = {
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};

D2ClientStrc * QServerClientBucketByName[256] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
};

D2ClientStrc * QServerClientBucketById[256] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
};

// also labelled: lpCriticalSection_008846a8
CRITICAL_SECTION gQServerClientByIdCs = {
    /* .DebugInfo = */ nullptr,
    /* .LockCount = */ 0,
    /* .RecursionCount = */ 0,
    /* .OwningThread = */ nullptr,
    /* .LockSemaphore = */ nullptr,
    /* .SpinCount = */ 0
};

// also labelled: lpCriticalSection_008846c0
CRITICAL_SECTION gQServerClientByNameCs = {
    /* .DebugInfo = */ nullptr,
    /* .LockCount = */ 0,
    /* .RecursionCount = */ 0,
    /* .OwningThread = */ nullptr,
    /* .LockSemaphore = */ nullptr,
    /* .SpinCount = */ 0
};

D2UniqueCandidatePoolStrc gUniqueCandidatePool = {
    /* .nGoldCodeInitFlag = */ 0,
    /* ._pad = */ 0,
    /* .aCandidates = */ {
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        },
        {
            /* .nUniqueIdx = */ 0,
            /* .nCumulativeWeight = */ 0
        }
    }
};

D2TaskQueueSlotStrc * gaTaskQueueHeadArray[32] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr
};

// also labelled: gpTaskQueueListHead, gppTaskQueueHead
D2LinkNodeStrc gsTaskQueueListHead = {
    /* .pNext = */ nullptr,
    /* .pPrev = */ nullptr
};

// also labelled: lpFrequency_0088c790
LARGE_INTEGER gnPerformanceFrequency = {};

// =============================================================================
// Initialized scalars
// =============================================================================

unsigned short QServerNextToken = 0x1;
uint32_t GameSeed = -0x1;
uint32_t dwCycleLastSecond = 0x19;
BOOL DontNoSafeGameBool = 0x1;
uint32_t gpInactiveMonsterStateFlagSentinel = 0xdeaddead;
uint32_t gnMonsterStateFlagMask1 = 0x1;
uint32_t gnMonsterStateFlagMask2 = 0x2;
uint8_t gbQuestReconnectMode = 0x1;
int nQuestDataExtendedSize = 0x25;
uint32_t gnObjectClassIdLight = 0x5;
uint32_t gnActCount = 0x5;
int gnNPCSpokenBitIndexMapCount = 0x23;
int gnObjectOperateCallbackCount = 0xa;
int SHRINESCOUNT = 0x18;
int MISSILESSRVHITFUNCS_SIZE = 0x47;
TSExportTableSync<SGAMEDATA, HSGAMEDATA__*, HSGAMEDATALOCK__*, CCritSect, 0> * gpQServerGameState = 0;
int StartingAct = 0;
uint32_t maxMemoryUsage = 0;
int gbQServerSendPlayerPos = 0;
D2BattleNetEventCallbackTable * BattleNetServerService = 0;
BOOL IsBattleNetServer = 0;
// also labelled: nCOMMAND_playersX
uint32_t PlayerCountOverride = 0;
uint32_t gptItemCodeArmor = 0;
uint32_t gptItemCodeSwordType = 0;
int gQServerClientTablesInitialized = 0;
BOOL DEBUGPRINT = 0;
uint32_t g_bWhisperSquelched = 0;
uint32_t g_bWhisperDelivered = 0;
uint32_t gnTaskQueueSlotCounter = 0;
uint32_t gnTaskQueueTailIndex = 0;
uint32_t gbPerformanceCounterAvailable = 0;
uint32_t gnMonsterSpawnTotalCount = 0;

// =============================================================================
// Uninitialized data (BSS)
// =============================================================================

uint8_t gaSkillLevelCaps;

namespace D2Common::Drlg::Maze {

} // namespace D2Common::Drlg::Maze

namespace Fog::Src::Excel {

} // namespace Fog::Src::Excel

namespace D2Client::Warden::NWardenClient {

} // namespace D2Client::Warden::NWardenClient

namespace D2Client::Warden {

} // namespace D2Client::Warden

namespace D2Client::UI {

} // namespace D2Client::UI

namespace D2Client::UI::Button::ButtonImplementation {

} // namespace D2Client::UI::Button::ButtonImplementation

namespace D2Client::UI::Button::ButtonWrapper {

} // namespace D2Client::UI::Button::ButtonWrapper

namespace D2Client::UI::Editbox::EditBoxImplementation {

} // namespace D2Client::UI::Editbox::EditBoxImplementation

namespace D2Client::UI::Editbox::EditBoxWrapper {

} // namespace D2Client::UI::Editbox::EditBoxWrapper

namespace D2Client::UI::Spinner::SpinnerImplementation {

} // namespace D2Client::UI::Spinner::SpinnerImplementation

namespace D2Client::UI::Spinner::SpinnerWrapper {

} // namespace D2Client::UI::Spinner::SpinnerWrapper

namespace D2Client::UNIT::Object {

} // namespace D2Client::UNIT::Object

namespace D2Client::UI::ListBox::ListBoxWrapper {

} // namespace D2Client::UI::ListBox::ListBoxWrapper

namespace D2Client::UI::ListBox::ListBoxImplementation {

} // namespace D2Client::UI::ListBox::ListBoxImplementation

namespace D2Win::_FONT {

} // namespace D2Win::_FONT

namespace D2Game::GAME::Event::Dispatch {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

int aTimerIndexUnitTypeLookupTable[6] = { 0x0, 0x1, 0x3, 0x2, 0x4, -0x1 };

D2TimerTypeMethodsStrc pTimerMethods = {
    /* .fpFunctionByType = */ {
        nullptr,
        nullptr,
        nullptr,
        &D2Game::ITEMS::ItemMode::ITEMMODE_ValidateTradeItem,
        &D2Game::ITEMS::ItemMode::ITEMMODE_NullSub,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        nullptr,
        &D2Game::ITEMS::ItemMode::ITEMMODE_ReturnZero2,
        nullptr,
        nullptr
    }
};

} // namespace D2Game::GAME::Event::Dispatch

namespace D2Game::GAME::Event::Dispatch::Player {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2TimerTypeMethodsExStrc pTimerMethods = {
    /* .fpFunctionExByType = */ {
        (fpTimerFunctionEx)&D2Game::PLAYER::PlayerModes::PLRMODES_ProcessPlayerMode,
        (fpTimerFunctionEx)&D2Game::PLAYER::PlayerModes::PLRMODES_OnModeComplete,
        nullptr,
        (fpTimerFunctionEx)&D2Game::PLAYER::PlayerModes::PLRMODES_PeriodicStatRegen,
        nullptr,
        (fpTimerFunctionEx)&D2Game::SKILLS::SkillsServer::SKILLS_DispatchStateActiveFunc,
        (fpTimerFunctionEx)&D2Game::PLAYER::PlayerModes::HoverTextEvent,
        nullptr,
        (fpTimerFunctionEx)&D2Game::SKILLS::SkillsServer::SKILLS_PeriodicSkillsCallback,
        (fpTimerFunctionEx)&D2Game::SKILLS::SkillsServer::SKILLS_PeriodicStatsCallback,
        nullptr,
        (fpTimerFunctionEx)&D2Game::PLAYER::PlayerModes::PLRMODES_BroadcastAllyAndPartyInfo,
        (fpTimerFunctionEx)&D2Game::PLAYER::PlayerModes::PLRMODES_RemoveExpiredStatLists,
        (fpTimerFunctionEx)&D2Game::PLAYER::PlayerTrade::PLRTRADE_ProcessTradeStateTick,
        nullptr
    }
};

} // namespace D2Game::GAME::Event::Dispatch::Player

namespace D2Game::GAME::Event::Dispatch::Object {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2TimerTypeMethodsStrc pTimerMethods = {
    /* .fpFunctionByType = */ {
        &D2Game::Objects::ObjectsMode::OBJMODE_UpdateTrapObject,
        &D2Game::Objects::ObjectsMode::OBJMODE_OpenObject,
        &D2Game::Objects::ObjectsMode::OBJMODE_UpdateFillProgress,
        &D2Game::Objects::ObjectsMode::OBJMODE_UpdateProximityStateMachine,
        &D2Game::Objects::ObjectsMode::OBJMODE_DispatchChestType,
        &D2Game::Objects::ObjectsMode::OBJMODE_DeactivateShrine,
        &D2Game::Objects::ObjectsMode::OBJMODE_UpdateHoverTextExpiry,
        &D2Game::Objects::ObjectsMode::QUEST_DispatchObjectActivation,
        &D2Game::Objects::ObjectsMode::OBJMODE_UpdateDayNightState,
        &D2Game::Objects::ObjectsMode::KillUnit,
        &D2Game::Objects::ObjectsMode::OBJMODE_RollChestLoot,
        &D2Game::Objects::ObjectsMode::OBJMODE_CreateRedPortal,
        nullptr,
        nullptr,
        nullptr
    }
};

} // namespace D2Game::GAME::Event::Dispatch::Object

namespace D2Game::GAME::Event::Dispatch::Monster {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2TimerTypeMethodsExStrc pTimerMethods = {
    /* .fpFunctionExByType = */ {
        (fpTimerFunctionEx)&D2Game::GAME::Event::Dispatch::Monster::MONMODE_DispatchDeathDrop,
        (fpTimerFunctionEx)&D2Game::GAME::Event::Dispatch::Monster::ExecuteDropHandlerFn3,
        (fpTimerFunctionEx)&D2Game::Monster::AI::MONSTERAI_ExecuteAiFunction,
        (fpTimerFunctionEx)&D2Game::GAME::Event::Dispatch::Monster::RegenAndPsnDecreaser,
        nullptr,
        (fpTimerFunctionEx)&D2Game::SKILLS::SkillsServer::SKILLS_DispatchStateActiveFunc,
        (fpTimerFunctionEx)&D2Game::GAME::Event::Dispatch::Monster::MONMODE_UpdateHoverTextExpiry,
        (fpTimerFunctionEx)&D2Game::Monsters::MONSTER_DispatchUModOnHit,
        (fpTimerFunctionEx)&D2Game::SKILLS::SkillsServer::SKILLS_PeriodicSkillsCallback,
        (fpTimerFunctionEx)&D2Game::SKILLS::SkillsServer::SKILLS_PeriodicStatsCallback,
        (fpTimerFunctionEx)&D2Game::GAME::Event::Dispatch::Monster::AI_ClearSwitchAiTargetParamsCallback,
        nullptr,
        (fpTimerFunctionEx)&D2Game::GAME::Event::Dispatch::Monster::RemoveStatListFromUnit,
        nullptr,
        nullptr
    }
};

} // namespace D2Game::GAME::Event::Dispatch::Monster

namespace D2Common::Chat::Ignorelist::ChatIgnoreList {

} // namespace D2Common::Chat::Ignorelist::ChatIgnoreList

namespace D2Common::Chat::Ignorelist::IgnoreList {

} // namespace D2Common::Chat::Ignorelist::IgnoreList

namespace D2Common::Drlg::Outdoors {

} // namespace D2Common::Drlg::Outdoors

namespace Define_the_symbol__ATL_MIXED {

} // namespace Define_the_symbol__ATL_MIXED

namespace Fog::_3rdparty::crashy {

} // namespace Fog::_3rdparty::crashy

namespace Storm::SFile {

} // namespace Storm::SFile

namespace Class::FILEREC {

} // namespace Class::FILEREC

namespace Class::EVENTREC {

} // namespace Class::EVENTREC

namespace Class::REQUEST {

} // namespace Class::REQUEST

namespace Class::AUDIOSTREAM {

} // namespace Class::AUDIOSTREAM

namespace Class::HANDLER {

} // namespace Class::HANDLER

namespace D2Client::CharScreen {

} // namespace D2Client::CharScreen

namespace D2Client::UI::Automap {

} // namespace D2Client::UI::Automap

namespace D2Game::GAME::Rendering {

} // namespace D2Game::GAME::Rendering

namespace D2Client::UI::Help {

} // namespace D2Client::UI::Help

namespace D2Client::UI::npcmenu {

} // namespace D2Client::UI::npcmenu

namespace D2Client::NPC {

} // namespace D2Client::NPC

namespace D2Client::UNIT::UnitSnd {

} // namespace D2Client::UNIT::UnitSnd

namespace D2Client::UI::ui {

} // namespace D2Client::UI::ui

namespace D2Game::Quests::QUESTS::Quest40 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x200,
            /* .nStringIndex = */ 0x4e2e,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x201,
            /* .nStringIndex = */ 0x4e45,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x202,
            /* .nStringIndex = */ 0x4e55,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x203,
            /* .nStringIndex = */ 0x4e61,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x208,
            /* .nStringIndex = */ 0x4e23,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x5
};

} // namespace D2Game::Quests::QUESTS::Quest40

namespace D2Game::Quests::QUESTS::A5Q1 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x1ff,
            /* .nStringIndex = */ 0x4e6d,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A5Q1

namespace D2Game::Quests::QUESTS::A5Q2 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x203,
            /* .nStringIndex = */ 0x4e80,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A5Q2

namespace D2Game::Quests::QUESTS::A5Q3 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x201,
            /* .nStringIndex = */ 0x4e94,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A5Q3

namespace D2Game::Quests::QUESTS::A5Q4 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x200,
            /* .nStringIndex = */ 0x4ea9,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A5Q4

namespace D2Game::Quests::QUESTS::A5Q5 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x203,
            /* .nStringIndex = */ 0x4eb9,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A5Q5

namespace D2Game::Quests::QUESTS::A5Q6 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x1ff,
            /* .nStringIndex = */ 0x4ecb,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0x208,
            /* .nStringIndex = */ 0x4eca,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0x201,
            /* .nStringIndex = */ 0x4ecc,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0x203,
            /* .nStringIndex = */ 0x4ece,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0x200,
            /* .nStringIndex = */ 0x4ecd,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x5
};

} // namespace D2Game::Quests::QUESTS::A5Q6

namespace D2Game::Quests::QUESTS::Quest37 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x94,
            /* .nStringIndex = */ 0xb,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x93,
            /* .nStringIndex = */ 0x2d,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x9a,
            /* .nStringIndex = */ 0x24,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x96,
            /* .nStringIndex = */ 0x18,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x4
};

} // namespace D2Game::Quests::QUESTS::Quest37

namespace D2Game::Quests::QUESTS::A1Q0 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x9b,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A1Q0

namespace D2Game::Quests::QUESTS::A1Q1 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x94,
            /* .nStringIndex = */ 0x40,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A1Q1

namespace D2Game::Quests::QUESTS::A1Q2 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x96,
            /* .nStringIndex = */ 0x51,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A1Q2

namespace D2Game::Quests::QUESTS::A1Q3 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x9a,
            /* .nStringIndex = */ 0x92,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A1Q3

namespace D2Game::Quests::QUESTS::A1Q4 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x94,
            /* .nStringIndex = */ 0x61,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A1Q4

namespace D2Game::Quests::QUESTS::A1Q5 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x109,
            /* .nStringIndex = */ 0x83,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0x9a,
            /* .nStringIndex = */ 0x81,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0x94,
            /* .nStringIndex = */ 0x82,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0x9b,
            /* .nStringIndex = */ 0x84,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0x96,
            /* .nStringIndex = */ 0x85,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0x93,
            /* .nStringIndex = */ 0x80,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x6
};

} // namespace D2Game::Quests::QUESTS::A1Q5

namespace D2Game::Quests::QUESTS::A1Q6 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x109,
            /* .nStringIndex = */ 0xa6,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A1Q6

namespace D2Game::Quests::QUESTS::A1Q7 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x10a,
            /* .nStringIndex = */ 0x3b,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A1Q7

namespace D2Game::Quests::QUESTS::Quest38 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xc7,
            /* .nStringIndex = */ 0xcb,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0xc6,
            /* .nStringIndex = */ 0xbe,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0xb0,
            /* .nStringIndex = */ 0xdd,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0xc8,
            /* .nStringIndex = */ 0xe6,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0xd2,
            /* .nStringIndex = */ 0xf1,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0xb2,
            /* .nStringIndex = */ 0x107,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0xaf,
            /* .nStringIndex = */ 0xd7,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0xca,
            /* .nStringIndex = */ 0x112,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0xb1,
            /* .nStringIndex = */ 0x11d,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x9
};

} // namespace D2Game::Quests::QUESTS::Quest38

namespace D2Game::Quests::QUESTS::A2Q0 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xc9,
            /* .nStringIndex = */ 0xfd,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A2Q0

namespace D2Game::Quests::QUESTS::A2Q1 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xb0,
            /* .nStringIndex = */ 0x130,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A2Q1

namespace D2Game::Quests::QUESTS::A2Q2 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xf4,
            /* .nStringIndex = */ 0x14f,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A2Q2

namespace D2Game::Quests::QUESTS::A2Q3 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xb0,
            /* .nStringIndex = */ 0x158,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xaf,
            /* .nStringIndex = */ 0x157,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xc6,
            /* .nStringIndex = */ 0x155,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xc7,
            /* .nStringIndex = */ 0x156,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xb1,
            /* .nStringIndex = */ 0x15c,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0xca,
            /* .nStringIndex = */ 0x15b,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xf4,
            /* .nStringIndex = */ 0x15e,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xd2,
            /* .nStringIndex = */ 0x15d,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xc8,
            /* .nStringIndex = */ 0x159,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xc9,
            /* .nStringIndex = */ 0x154,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xb2,
            /* .nStringIndex = */ 0x15a,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0xb
};

} // namespace D2Game::Quests::QUESTS::A2Q3

namespace D2Game::Quests::QUESTS::A2Q4 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xb1,
            /* .nStringIndex = */ 0x175,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A2Q4

namespace D2Game::Quests::QUESTS::A2Q5 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xb0,
            /* .nStringIndex = */ 0x19e,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xaf,
            /* .nStringIndex = */ 0x19d,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xc6,
            /* .nStringIndex = */ 0x198,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xc7,
            /* .nStringIndex = */ 0x1a1,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xb1,
            /* .nStringIndex = */ 0x19a,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xca,
            /* .nStringIndex = */ 0x19b,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xf4,
            /* .nStringIndex = */ 0x1a2,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xd2,
            /* .nStringIndex = */ 0x19c,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xc9,
            /* .nStringIndex = */ 0x199,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xc8,
            /* .nStringIndex = */ 0x19f,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0xb2,
            /* .nStringIndex = */ 0x1a0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0xb
};

} // namespace D2Game::Quests::QUESTS::A2Q5

namespace D2Game::Quests::QUESTS::A2Q6 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xc9,
            /* .nStringIndex = */ 0x1ae,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A2Q6

namespace D2Game::Quests::QUESTS::A2Q7 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x179,
            /* .nStringIndex = */ 0x3b,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A2Q7

namespace D2Game::Quests::QUESTS::A2Q8 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x17a,
            /* .nStringIndex = */ 0x12f,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A2Q8

namespace D2Common::Monsters::MONSTERS::Umod {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

fpUmodInit aUmodInitTable[43] = {
    nullptr,
    &D2Game::Monsters::Umod::MONUMOD_RollNameSeed,
    &D2Game::Monsters::Umod::MONUMOD_ApplyHpBonus,
    nullptr,
    &D2Game::Monsters::Umod::MONUMOD_ApplyChampionLevelBonus,
    &D2Game::Monsters::Umod::ExtraStrong,
    &D2Game::Monsters::Umod::ExtraFast,
    nullptr,
    &D2Game::Monsters::Umod::MagicResist,
    &D2Game::Monsters::Umod::FireEnchanted,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &D2Game::Monsters::Umod::MONUMOD_ApplyChampionStats,
    &D2Game::Monsters::Umod::LightningEnchanted,
    &D2Game::Monsters::Umod::ColdEnchanted,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &D2Game::Monsters::Umod::PoisonEnchanted,
    nullptr,
    &D2Game::Monsters::Umod::ManaBurn,
    &D2Game::Monsters::Umod::TeleHeal,
    &D2Game::Monsters::Umod::MagicResist,
    &D2Game::Monsters::Umod::MagicResist,
    nullptr,
    &D2Game::Monsters::Umod::AuraEnchanted,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &D2Game::Monsters::Umod::MONUMOD_ApplyColdEnchant,
    &D2Game::Monsters::Umod::MONUMOD_ApplyBerserker,
    &D2Game::Monsters::Umod::MONUMOD_ApplyPossessed,
    &D2Game::Monsters::Umod::MONUMOD_ApplyFanatic,
    nullptr,
    &D2Game::Monsters::Umod::MONUMOD_SetEventTimer,
    nullptr
};

} // namespace D2Common::Monsters::MONSTERS::Umod

namespace D2Game::Quests::QUESTS::A4Q0 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x16f,
            /* .nStringIndex = */ 0x298,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A4Q0

namespace D2Game::Quests::QUESTS::A4Q1 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x16f,
            /* .nStringIndex = */ 0x29e,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A4Q1

namespace D2Game::Quests::QUESTS::A4Q2 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x16f,
            /* .nStringIndex = */ 0x2a9,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A4Q2

namespace D2Game::Quests::QUESTS::A4Q3 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xf6,
            /* .nStringIndex = */ 0x2a6,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A4Q3

namespace D2Game::Quests::QUESTS::A4Q4 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x198,
            /* .nStringIndex = */ 0x29c,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A4Q4

namespace D2Game::Quests::QUESTS::Quest39 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0x129,
            /* .nStringIndex = */ 0x1c5,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0xf5,
            /* .nStringIndex = */ 0x1ca,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x108,
            /* .nStringIndex = */ 0x1de,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0xfc,
            /* .nStringIndex = */ 0x1ea,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0xfe,
            /* .nStringIndex = */ 0x1f5,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0xff,
            /* .nStringIndex = */ 0x202,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x6
};

} // namespace D2Game::Quests::QUESTS::Quest39

namespace D2Game::Quests::QUESTS::A3Q0 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xfd,
            /* .nStringIndex = */ 0x1d1,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A3Q0

namespace D2Game::Quests::QUESTS::A3Q1 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xfe,
            /* .nStringIndex = */ 0x225,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A3Q1

namespace D2Game::Quests::QUESTS::A3Q2 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xf5,
            /* .nStringIndex = */ 0x21f,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A3Q2

namespace D2Game::Quests::QUESTS::A3Q3 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xfd,
            /* .nStringIndex = */ 0x23b,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A3Q3

namespace D2Game::Quests::QUESTS::A3Q4 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xf5,
            /* .nStringIndex = */ 0x20f,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0xfc,
            /* .nStringIndex = */ 0x210,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x2
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x2
};

} // namespace D2Game::Quests::QUESTS::A3Q4

namespace D2Game::Quests::QUESTS::A3Q5 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xff,
            /* .nStringIndex = */ 0x252,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A3Q5

namespace D2Game::Quests::QUESTS::A3Q6 {

// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

D2NPCMessageTableStrc aNpcGossipData = {
    /* .pMessages = */ {
        {
            /* .nMonStatsId = */ 0xff,
            /* .nStringIndex = */ 0x274,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x1
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        },
        {
            /* .nMonStatsId = */ 0x0,
            /* .nStringIndex = */ 0x0,
            /* .nPad = */ 0x0,
            /* .bMenu = */ 0x0
        }
    },
    /* .nMessagesCount = */ 0x1
};

} // namespace D2Game::Quests::QUESTS::A3Q6

namespace D2Client::Waypoint {

} // namespace D2Client::Waypoint

namespace D2Common::Drlg::DrlgGrid {

} // namespace D2Common::Drlg::DrlgGrid

namespace Fog::Memory {

} // namespace Fog::Memory

namespace Fog::Debug {

} // namespace Fog::Debug

namespace D2Game::Save {

} // namespace D2Game::Save

namespace D2Client::MCP {

} // namespace D2Client::MCP

namespace D2Client::Bnet {

} // namespace D2Client::Bnet

namespace D2Game::GameData {

} // namespace D2Game::GameData

namespace D2Client::GAME::Record {

} // namespace D2Client::GAME::Record

namespace D2Client::UI::Dialog {

} // namespace D2Client::UI::Dialog

namespace D2Client::_Selection {

} // namespace D2Client::_Selection

namespace D2Client::Cursor {

} // namespace D2Client::Cursor

namespace D2Client::Draw::Weather {

} // namespace D2Client::Draw::Weather

namespace D2Client::Draw::LightMap {

} // namespace D2Client::Draw::LightMap

namespace D2Client::GAME::View {

} // namespace D2Client::GAME::View

namespace D2Client::GAME::RosterPets {

} // namespace D2Client::GAME::RosterPets

namespace D2Client::GAME::Roster {

} // namespace D2Client::GAME::Roster

namespace D2Client::UI::Inv {

} // namespace D2Client::UI::Inv

namespace D2Client::UI::Hireables {

} // namespace D2Client::UI::Hireables

namespace D2Client::UI::Panel {

} // namespace D2Client::UI::Panel

namespace D2Client::UI::Party {

} // namespace D2Client::UI::Party

namespace D2Client::_Interaction {

} // namespace D2Client::_Interaction

namespace D2Client::Merc {

} // namespace D2Client::Merc

namespace D2Client::Mouse {

} // namespace D2Client::Mouse

namespace D2Client::Forms {

} // namespace D2Client::Forms

namespace D2Client::_CdKey {

} // namespace D2Client::_CdKey

namespace D2Direct3D::Renderer {

} // namespace D2Direct3D::Renderer
