/**
 * Auto-generated global data definitions
 * Binary: Game.exe
 */

#include "globals/globals.h"
#include "D2Client/D2ClientStrc.h"
#include "D2Launch/CharSel.h"
#include "D2Launch/D2Launch.h"
#include "D2Launch/Launcher.h"
#include "D2Launch/MainMenus.h"


// =============================================================================
// Initialized data (arrays, structs, tables)
// =============================================================================

uint8_t gaNewCharDefaultEquipTemplate[16] = {
    0x1,
    0x1,
    0x1,
    0x1,
    0x1,
    0x0,
    0x0,
    0x0,
    0x1,
    0x1,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0,
    0x0
};

int32_t gaMenuFormFontParamsFont1[2] = { 0x1, 0x0 };

FORMS_PredefinedFormStrc gaPredefinedForms[333] = {
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x0, 0x1df, 0x280, 0x1e0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_blizno,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::UIMENU_PlayIntroAndReturnToMainScreen,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Timer,
        /* .aParams = */ { 0x8, 0x0, 0x0, 0x0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::UIMENU_PlayIntroAndReturnToMainScreen,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x0, 0x257, 0x320, 0x258 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_trademark,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::thunk_UIMENU_MainMenu,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)&D2Launch::MainMenus::thunk_UIMENU_MainMenu,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Timer,
        /* .aParams = */ { 0x9, 0x0, 0x0, 0x0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::thunk_UIMENU_MainMenu,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x64, 0x244, 0x258, 0x50 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0xf0, 0x78, 0x140, 0x97 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_Diablo2,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_AnimImage,
        /* .aParams = */ { 0x190, 0x78, 0xb5, 0xaa },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)gaMainMenuLogoLeftAnimFrames,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_AnimImage,
        /* .aParams = */ { 0x190, 0x78, 0xbc, 0xb1 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)gaMainMenuLogoRightAnimFrames,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x0, 0x257, 0x320, 0x258 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_TitleScreen_or_gameselectscreenEXP,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0xe0, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x13f2,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused9,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x10a, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x13f3,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank02,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused11,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x123, 0x110, 0x19 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_NarrowButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused8,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x14d, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x13f4,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::Test,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x210, 0x87, 0x19 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x13f6,
        /* .pDC6 = */ (DC6*)&DC6_CharSelect_ShortButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_InitCreditsScreen,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x192, 0x210, 0x87, 0x19 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x13f7,
        /* .pDC6 = */ (DC6*)&DC6_CharSelect_ShortButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_ShowCinematicsMenu,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x238, 0x110, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13f5,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_CleanupSoundAndClearMessageLoop,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x144, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x13f2,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused9,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x16e, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x13f3,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank02,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused11,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x187, 0x110, 0x19 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_NarrowButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused8,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x1b1, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x13f4,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::Test,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x96, 0x12c, 0x1f4, 0x64 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont3,
        /* .nFlagsOrType = */ 0x22
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x13f, 0x15b, 0xa9, 0x1a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_textbox2,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x13f, 0x191, 0xa9, 0x1a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_textbox2,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x13f, 0x1c7, 0xa9, 0x1a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_textbox2,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x13f, 0x1c7, 0xa9, 0x1a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_textbox2,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x13f, 0x1fd, 0xa9, 0x1a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_textbox2,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x141, 0x154, 0x12c, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x141, 0x18a, 0x12c, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x141, 0x1c0, 0x12c, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x141, 0x1c0, 0x12c, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x141, 0x1f6, 0x12c, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x0, 0x104, 0x320, 0x32 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xc8, 0x15e, 0x190, 0x64 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x0, 0x136, 0x320, 0x32 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0x142, 0x156, 0xa2, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_Unused13,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0x142, 0x18c, 0xa2, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_Unused13,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x21
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x23c, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x1465,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::UIMENU_AndOneMorePleaseWait,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x210, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x2b64,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressSaveAccountNameAndShowDisconnected,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x1e4, 0x110, 0x23 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x14a8,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_3WideButtonBlank,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::MAINMENU_Unused13,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x21, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ed,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENUS_OnPressReturnToMainMenu_ForCreditsAndMainMenuAgain,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x24e, 0x221, 0xcd, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x0, 0x257, 0x320, 0x258 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_CharSelect_creditsbckg,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x21, 0x242, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ed,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENUS_OnPressReturnToMainMenu_ForCreditsAndMainMenuAgain,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x230, 0x267, 0xfa, 0x262 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont4Ex1,
        /* .nFlagsOrType = */ 0x90
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x23a, 0x267, 0xfa, 0x262 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont4Ex1,
        /* .nFlagsOrType = */ 0x80
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x1b8, 0x267, 0xfa, 0x262 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont4Ex1,
        /* .nFlagsOrType = */ 0x82
    },
    {
        /* .neD2FormType = */ FORM_Timer,
        /* .aParams = */ { 0x32, 0x0, 0x0, 0x0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressCreditsEndCheck,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x190, 0x267, 0xfa, 0x262 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont4Ex1,
        /* .nFlagsOrType = */ 0x90
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x19a, 0x267, 0xfa, 0x262 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont4Ex1,
        /* .nFlagsOrType = */ 0x80
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x118, 0x267, 0xfa, 0x262 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont4Ex1,
        /* .nFlagsOrType = */ 0x82
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0xed, 0x22b, 0x146, 0x155 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CinematicsSelection,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x106, 0x11b, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x106, 0x13c, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x1029,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused1,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x106, 0x167, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x102a,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused2,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x106, 0x192, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x102b,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused3,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x106, 0x1bd, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x102c,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused4,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x106, 0x1e8, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x13f9,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused5,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x14e, 0x21a, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressReloadMediaMpqAndReturnToMainMenu,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x119, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::MAINMENU_ShowCinematicsMenuAndSetFlag,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x1a5, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENUS_OnPressSetInsertPlayCd_ForCinematicDisc,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x15f, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressSetInsertPlayCd,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0xed, 0x1f9, 0x146, 0x1ab },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CinematicsSelectionEXP,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x106, 0x99, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x106, 0xb5, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x5525,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused1,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x106, 0xe0, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x5526,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused2,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x106, 0x10c, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x5527,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused3,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x106, 0x136, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x5528,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused4,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x106, 0x161, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x5529,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused5,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x106, 0x18c, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x552a,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused6,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x106, 0x1b7, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x552b,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused7,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x14e, 0x1e8, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressReloadMediaMpqAndReturnToMainMenu,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0xed, 0x22b, 0x154, 0x154 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_GWListBox,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xed, 0x10e, 0x154, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x101, 0x159, 0x140, 0x54 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont0Ex4,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x101, 0x1f4, 0x124, 0xa0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_joingamescrollbars,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused12,
        /* .pTypeArg1 = */ (void*)gaMenuTextBoxScrollbarGeom3,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0xd
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x119, 0x21a, 0x60, 0x20 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::StorePreferedRealmAgain,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x1b4, 0x21a, 0x60, 0x20 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressDestroyListsAndReturnToMainMenu,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x67, 0x20e, 0x251, 0x1c3 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_TermsofUseBckg,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x78, 0x1d3, 0x230, 0x13e },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_joingamescrollbars,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)gaMenuTextBoxScrollbarGeom2,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont4,
        /* .nFlagsOrType = */ 0x4
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x20d, 0x201, 0x80, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x143d,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressCreateBattleNetAccount,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x85, 0x201, 0x80, 0x23 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x143e,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressReturnToMainMenuAgain,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x67, 0xad, 0x23a, 0x45 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont3,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x384, 0x384, 0x80, 0x23 },
        /* .nExtraParam = */ 0x26,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::MAINMENU_ScrollListExUp,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x6
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x384, 0x384, 0x80, 0x23 },
        /* .nExtraParam = */ 0x28,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_ScrollListExDown,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x6
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0x142, 0x156, 0xa2, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_Unused15,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0x142, 0x18c, 0xa2, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_Unused15,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x21
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0x142, 0x1c2, 0xa2, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_Unused15,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x21
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x273, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::MAINMENU_Unused15,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x21, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ed,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressReturnToMainMenuAgain,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0x142, 0x156, 0xa2, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_HandlePasswordChange,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0x142, 0x18c, 0xa2, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_HandlePasswordChange,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x21
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0x142, 0x1c2, 0xa2, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_HandlePasswordChange,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x21
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0x142, 0x1f8, 0xa2, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_HandlePasswordChange,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x21
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x273, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::MAINMENU_HandlePasswordChange,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x21, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ed,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressShowDisconnectedFromBattleNet2,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x67, 0xad, 0x23a, 0x45 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont3,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x6e, 0x1e0, 0x23a, 0x13e },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x6e, 0x262, 0x23a, 0x13e },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x6e, 0x2bc, 0x23a, 0x13e },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x20d, 0x201, 0x80, 0x23 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused14,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x85, 0x201, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressDestroyListAndReturnToMainMenuAgain,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x201, 0x50, 0x110, 0x49 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CurRealm_or_Realmselect,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x22f, 0x21, 0xb7, 0x12 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x201, 0x69, 0x110, 0x19 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x2b31,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_NarrowButtonBlank02_or_RealmSelectbuttonthin,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_OpenRealmChangeDialog,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x210, 0x60, 0xf6, 0x2f },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont3,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x261, 0x53, 0xb6, 0x47 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CurRealm_or_Realmselect,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x275, 0x2c, 0x91, 0x15 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x261, 0x71, 0xb6, 0x1e },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x2b31,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_NarrowButtonBlank02_or_RealmSelectbuttonthin,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_OpenRealmChangeDialog,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x272, 0x64, 0x97, 0x2c },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x1c3, 0x1c7, 0x154, 0x154 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_GWListBox,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x1c3, 0xad, 0x154, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x1cd, 0xe6, 0x140, 0x46 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont0Ex4,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x1d7, 0x190, 0x124, 0xa0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_joingamescrollbars,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleRealmChange,
        /* .pTypeArg1 = */ (void*)gaMenuTextBoxScrollbarGeom4,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0xd
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x1ef, 0x1b6, 0x60, 0x20 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::ChangeClosedRealmChoice,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x28a, 0x1b6, 0x60, 0x20 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_OnPressLoadCharListForPreferredRealm,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x7f, 0x1c7, 0x154, 0x154 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_GWListBox,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x7f, 0xad, 0x154, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x89, 0xe6, 0x140, 0x46 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont0Ex4,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x93, 0x190, 0x124, 0xa0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_joingamescrollbars,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleRealmChange,
        /* .pTypeArg1 = */ (void*)gaMenuTextBoxScrollbarGeom4,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0xd
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0xab, 0x1b6, 0x60, 0x20 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::ChangeClosedRealmChoice,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x146, 0x1b6, 0x60, 0x20 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_OnPressLoadCharListForPreferredRealm,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x21, 0x212, 0x1c0, 0x78 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont4,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Timer,
        /* .aParams = */ { 0x32, 0x0, 0x0, 0x0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_OnPressPumpRealmCharListLoad,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x202, 0x23c, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x1499,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::thunk_UIMENU_CreateHeroSinglePlayer,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x21, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ed,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::UIMENU_DisconnectAndReturnToMainMenu,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0xc1, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x1498,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::CharSel::CHARSEL_OnPressConfirmDeleteCharacter,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x161, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::CharSel::SelectCharHandler,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x202, 0x99, 0xc8, 0x5c },
        /* .nExtraParam = */ 0x4c,
        /* .nLabelAsLocaleStringId = */ 0x5,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x202, 0xf6, 0xc8, 0x5c },
        /* .nExtraParam = */ 0x4c,
        /* .nLabelAsLocaleStringId = */ 0x5,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x202, 0x153, 0xc8, 0x5c },
        /* .nExtraParam = */ 0x4c,
        /* .nLabelAsLocaleStringId = */ 0x5,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x202, 0x1b0, 0xc8, 0x5c },
        /* .nExtraParam = */ 0x4c,
        /* .nLabelAsLocaleStringId = */ 0x5,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x202, 0x20d, 0xc8, 0x5c },
        /* .nExtraParam = */ 0x4c,
        /* .nLabelAsLocaleStringId = */ 0x5,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x25, 0xb2, 0xc8, 0x5c },
        /* .nExtraParam = */ 0x4c,
        /* .nLabelAsLocaleStringId = */ 0x3,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x135, 0xb2, 0xc8, 0x5c },
        /* .nExtraParam = */ 0x4c,
        /* .nLabelAsLocaleStringId = */ 0x3,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x25, 0x10f, 0xc8, 0x5c },
        /* .nExtraParam = */ 0x4c,
        /* .nLabelAsLocaleStringId = */ 0x3,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x135, 0x10f, 0xc8, 0x5c },
        /* .nExtraParam = */ 0x4c,
        /* .nLabelAsLocaleStringId = */ 0x3,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x25, 0x16c, 0xc8, 0x5c },
        /* .nExtraParam = */ 0x4c,
        /* .nLabelAsLocaleStringId = */ 0x3,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x135, 0x16c, 0xc8, 0x5c },
        /* .nExtraParam = */ 0x4c,
        /* .nLabelAsLocaleStringId = */ 0x3,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x25, 0x1c9, 0xc8, 0x5c },
        /* .nExtraParam = */ 0x4c,
        /* .nLabelAsLocaleStringId = */ 0x3,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x135, 0x1c9, 0xc8, 0x5c },
        /* .nExtraParam = */ 0x4c,
        /* .nLabelAsLocaleStringId = */ 0x3,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xed, 0xb2, 0x48, 0x5d },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x1fd, 0xb2, 0x48, 0x5d },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xed, 0x10f, 0x48, 0x5d },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x1fd, 0x10f, 0x48, 0x5d },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xed, 0x16c, 0x48, 0x5d },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x1fd, 0x16c, 0x48, 0x5d },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xed, 0x1c9, 0x48, 0x5d },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x1fd, 0x1c9, 0x48, 0x5d },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::CHARSEL_HandleCharListClick,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x20
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x2d, 0x13e, 0x213, 0x8c },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x25, 0xb2, 0x223, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont4,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x202, 0x3e8, 0x110, 0x5d },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_CharSelect_charselectbox,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)&D2Launch::CharSel::CHARSEL_HandleKeyNavClassic,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x202, 0x3e8, 0x110, 0x5d },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_CharSelect_charselectboxgrey,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)&D2Launch::CharSel::CHARSEL_HandleKeyNavClassic,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x202, 0x181, 0x110, 0x5d },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x27a, 0x32, 0x1d, 0x14 },
        /* .nExtraParam = */ 0x69,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_CharSelect_selectchararrows,
        /* .fpOnPressCallback = */ &D2Launch::CharSel::CHARSEL_OnPressScrollCharListUp,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x8
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x27a, 0x22b, 0x1d, 0x14 },
        /* .nExtraParam = */ 0x63,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_CharSelect_selectchararrows,
        /* .fpOnPressCallback = */ &D2Launch::CharSel::CHARSEL_OnPressScrollCharListDown,
        /* .pTypeArg1 = */ (void *)0x00000002,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x10
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x46, 0x67, 0x1c2, 0x32 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont3,
        /* .nFlagsOrType = */ 0x22
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x55, 0x4e, 0x1d2, 0x2a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont3,
        /* .nFlagsOrType = */ 0x22
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x56, 0x8f, 0x190, 0x32 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x56, 0xb2, 0x190, 0x32 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x200, 0x96, 0x54, 0x56 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_CharSelect_CreateNewCharImage,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)&D2Launch::CharSel::CHARSEL_HandleKeyNavClassic,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x56, 0x12c, 0x190, 0xc8 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont8,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x0, 0x257, 0x320, 0x258 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_CharSelect__characterselectscreenEXP,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x273, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::CharSel::SelectCharHandler,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x21, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ed,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::UIMENU_DisconnectAndReturnToMainMenu,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x21, 0x210, 0xa8, 0x3c },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x2a50,
        /* .pDC6 = */ (DC6*)&DC6_CharSelect_TallButtonBlank,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::thunk_UIMENU_CreateHeroSinglePlayer,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x40
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0xe9, 0x210, 0xa8, 0x3c },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x58cc,
        /* .pDC6 = */ (DC6*)&DC6_CharSelect_TallButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressShowExpansionCreditsPage,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x40
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x1b1, 0x210, 0xa8, 0x3c },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x1498,
        /* .pDC6 = */ (DC6*)&DC6_CharSelect_TallButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::CharSel::CHARSEL_OnPressConfirmDeleteCharacter,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x40
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x234, 0x1c9, 0x22, 0x173 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_joingamescrollbars,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::MAINMENU_CharSelScrollbarCallback,
        /* .pTypeArg1 = */ (void*)gaMenuTextBoxScrollbarGeom5,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x5
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x129, 0x110, 0x23 },
        /* .nExtraParam = */ 0x52,
        /* .nLabelAsLocaleStringId = */ 0x2722,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::CharSel::UIMENU_Callback_NormalButtonSingleplayerTcpIp,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x154, 0x110, 0x23 },
        /* .nExtraParam = */ 0x4e,
        /* .nLabelAsLocaleStringId = */ 0x2721,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::CharSel::UIMENU_Callback_NightmareButtonSingleplayerTcpIp,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x17f, 0x110, 0x23 },
        /* .nExtraParam = */ 0x48,
        /* .nLabelAsLocaleStringId = */ 0x2720,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::CharSel::UIMENU_Callback_HellButtonSingleplayerTcpIp,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x108, 0x104, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0xed, 0x190, 0x146, 0xc8 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_CharSelect_DifficultyLevels,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x384, 0x384, 0xa, 0xa },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressDestroyFormList,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x0, 0x50, 0x320, 0x32 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x21, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ed,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumSelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressGotoCharacterSelect,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x273, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumSelButtonBlank,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::MAINMENU_Unused16,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x0, 0x257, 0x320, 0x258 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CharacterCreate_or_charactercreationscreenEXP,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_AnimImage,
        /* .aParams = */ { 0x159, 0x1d6, 0x6e, 0x7f },
        /* .nExtraParam = */ 0x1,
        /* .nLabelAsLocaleStringId = */ 0x3,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_fire,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_AnimImage,
        /* .aParams = */ { 0x159, 0x1c6, 0x6e, 0x7f },
        /* .nExtraParam = */ 0x1,
        /* .nLabelAsLocaleStringId = */ 0x3,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_fire,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_AnimImage,
        /* .aParams = */ { 0xc3, 0x155, 0x58, 0xb8 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::ClickOnClassCreate,
        /* .pTypeArg1 = */ (void*)gaCharSelectAnimFramesAmazon,
        /* .pTypeArg2 = */ (void*)&D2Launch::MainMenus::MAINMENU_SetAmazonDescription,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_AnimImage,
        /* .aParams = */ { 0x12d, 0x14d, 0x58, 0xb8 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::ClickOnClassCreate,
        /* .pTypeArg1 = */ (void*)gaCharSelectAnimFramesNecromancer,
        /* .pTypeArg2 = */ (void*)&D2Launch::MainMenus::MAINMENU_SetNecromancerDescription,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_AnimImage,
        /* .aParams = */ { 0x190, 0x14a, 0x58, 0xb8 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::ClickOnClassCreate,
        /* .pTypeArg1 = */ (void*)gaCharSelectAnimFramesBarbarian,
        /* .pTypeArg2 = */ (void*)&D2Launch::MainMenus::MAINMENU_SetBarbarianDescription,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_AnimImage,
        /* .aParams = */ { 0x209, 0x158, 0x58, 0xb8 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::ClickOnClassCreate,
        /* .pTypeArg1 = */ (void*)gaCharSelectAnimFramesSorceress,
        /* .pTypeArg2 = */ (void*)&D2Launch::MainMenus::MAINMENU_SetSorceressDescription,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_AnimImage,
        /* .aParams = */ { 0x262, 0x167, 0x58, 0xb8 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::ClickOnClassCreate,
        /* .pTypeArg1 = */ (void*)gaCharSelectAnimFramesPaladin,
        /* .pTypeArg2 = */ (void*)&D2Launch::MainMenus::MAINMENU_SetPaladinDescription,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_AnimImage,
        /* .aParams = */ { 0xd9, 0x168, 0x58, 0xb8 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::ClickOnClassCreate,
        /* .pTypeArg1 = */ (void*)gaCharSelectAnimFramesNecromancer,
        /* .pTypeArg2 = */ (void*)&D2Launch::MainMenus::MAINMENU_SetNecromancerDescription,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_AnimImage,
        /* .aParams = */ { 0x272, 0x161, 0x58, 0xb8 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::ClickOnClassCreate,
        /* .pTypeArg1 = */ (void*)gaCharSelectAnimFramesSorceress,
        /* .pTypeArg2 = */ (void*)&D2Launch::MainMenus::MAINMENU_SetSorceressDescription,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_AnimImage,
        /* .aParams = */ { 0x209, 0x153, 0x58, 0xb8 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::ClickOnClassCreate,
        /* .pTypeArg1 = */ (void*)gaCharSelectAnimFramesPaladin,
        /* .pTypeArg2 = */ (void*)&D2Launch::MainMenus::MAINMENU_SetPaladinDescription,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_AnimImage,
        /* .aParams = */ { 0x64, 0x151, 0x58, 0xb8 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::ClickOnClassCreate,
        /* .pTypeArg1 = */ (void*)gaCharSelectAnimFramesAmazon,
        /* .pTypeArg2 = */ (void*)&D2Launch::MainMenus::MAINMENU_SetAmazonDescription,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x153, 0x245, 0x64, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x13f, 0x230, 0xf, 0x10 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_clickbox,
        /* .fpOnPressCallback = */ &D2Launch::UIMENU_ToggleHardcoreMode,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x153, 0x231, 0xc8, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x13f, 0x21c, 0xf, 0x10 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_clickbox,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressToggleLadderFlag,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x153, 0x245, 0xc8, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x13f, 0x230, 0xf, 0x10 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_clickbox,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressToggleLadderFlag,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x153, 0x259, 0xc8, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x13f, 0x244, 0xf, 0x10 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_clickbox,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressToggleLadderFlag,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x0, 0xb4, 0x320, 0x64 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xfa, 0xd2, 0x12c, 0x64 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xd2, 0x262, 0x1ae, 0x78 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont0Ex4,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x13f, 0x207, 0xa9, 0x1a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_textbox,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x141, 0x200, 0xc8, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x153, 0x231, 0x64, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x13f, 0x21c, 0xf, 0x10 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_clickbox,
        /* .fpOnPressCallback = */ &D2Launch::UIMENU_ToggleHardcoreMode,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0x13e, 0x1fe, 0x9d, 0x10 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_Unused16,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x10c, 0x15e, 0x108, 0xb0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_PopUpOKCancel,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x119, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_OkCancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressCreateHeroSinglePlayer,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x1a5, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_OkCancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressCommitNewCharacterAndStartGame,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x10c, 0x140, 0x108, 0x78 },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x8,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_AnimImage,
        /* .aParams = */ { 0xe8, 0x16c, 0x58, 0xb8 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::ClickOnClassCreate,
        /* .pTypeArg1 = */ (void*)gaCharSelectAnimFramesAssassin,
        /* .pTypeArg2 = */ (void*)&D2Launch::MainMenus::MAINMENU_SetAssassinDescription,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_AnimImage,
        /* .aParams = */ { 0x2d0, 0x172, 0x58, 0xb8 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::ClickOnClassCreate,
        /* .pTypeArg1 = */ (void*)gaCharSelectAnimFramesDruid,
        /* .pTypeArg2 = */ (void*)&D2Launch::MainMenus::MAINMENU_SetDruidDescription,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x153, 0x231, 0xc8, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x13f, 0x21c, 0xf, 0x10 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_clickbox,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressToggleExpansionFlag,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x13f, 0x21c, 0xf, 0x10 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_joingameclickboxgrey,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x10c, 0x15e, 0x108, 0xb0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_PopUpOKCancel2,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x119, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x142f,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::CharSel::CHARSEL_OnPressDestroyFormList,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x1a5, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x142e,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::LAUNCHER_StartGameWithSelectedCharacter,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x10c, 0x140, 0x108, 0x78 },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x8,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x10c, 0x15e, 0x108, 0xb0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_PopUpOKCancel2,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x119, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x142f,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressDestroyFormListIfExpansion,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x1a5, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x142e,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::Launcher::HandleUpdateToExpansion,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x10c, 0x136, 0x108, 0x78 },
        /* .nExtraParam = */ 0x9,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont0Ex4,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x10c, 0x15e, 0x108, 0xb0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_PopUpOK,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x15f, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressInvokeCurrentMenuInstance,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x10c, 0x12c, 0x108, 0x64 },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x8,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x15f, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressInvokeCurrentMenuInstance,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0xde, 0x1aa, 0x154, 0xe0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_PopUp_340x224,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x14a, 0x1a0, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressInvokeCurrentMenuInstance,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xde, 0x118, 0x154, 0x3c },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xde, 0x168, 0x154, 0x46 },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x8,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xde, 0x172, 0x154, 0x14 },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0xc3, 0x1a6, 0x19a, 0xf5 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_PopUpWide,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x14f, 0x19c, 0x80, 0x23 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressInvokeCurrentMenuInstance,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xc3, 0xed, 0x19a, 0x28 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xc7, 0x179, 0x192, 0x8c },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x8,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x9e, 0x1cc, 0x1e5, 0x122 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_PopUpLargest,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x14f, 0x1c2, 0x80, 0x23 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressInvokeCurrentMenuInstance,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x9e, 0xdc, 0x1e5, 0x28 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xa2, 0x1a4, 0x1dd, 0xc8 },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xa2, 0x140, 0x1dd, 0x64 },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xa2, 0x1a4, 0x1dd, 0x64 },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x9e, 0x1cc, 0x1e5, 0x122 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_PopUpLargest,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x14f, 0x1c2, 0x80, 0x23 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressInvokeCurrentMenuInstance,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x9e, 0xdc, 0x1e5, 0x28 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xa2, 0x10e, 0x1dd, 0x32 },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x9e, 0x136, 0x1e5, 0x28 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xa2, 0x1a4, 0x1dd, 0x64 },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x10c, 0x15e, 0x108, 0xb0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_PopUpOK2,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x15f, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_OkCancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressInvokeCurrentMenuInstance,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x10c, 0x140, 0x108, 0x78 },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x8,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x15f, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_OkCancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressInvokeCurrentMenuInstance,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Timer,
        /* .aParams = */ { 0x28, 0x0, 0x0, 0x0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressShowBnetConnectFailedPopup,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x15f, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressCancelTermsOfServiceDownload,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x15f, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressCancelTermsOfServiceDownload,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x10c, 0x151, 0x108, 0x78 },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x8,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x136, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x13fb,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused10,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x15e, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x13fc,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressTcpIpOptions,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x238, 0x110, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressReturnToMainMenu,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x0, 0x257, 0x320, 0x258 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_tcpipbckg_or_tcpipscreen,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x64, 0x4c, 0x258, 0x28 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont3,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x10e, 0x9c, 0x110, 0x28 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x109, 0xab, 0x110, 0x28 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x109, 0xce, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x13fe,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MAINMENU_ConnectViaTCPIPAndSelectChar,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)&D2Launch::MainMenus::MAINMENU_DisableControlIfDataNonZero,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x109, 0x108, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x13ff,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::UIMENU_TCPIPAddressInput,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)&D2Launch::MainMenus::MAINMENU_DisableControlIfDataNonZero2,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x109, 0x208, 0x110, 0xd2 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont8,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x109, 0x208, 0x110, 0xd2 },
        /* .nExtraParam = */ 0x2,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont8,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x27, 0x23b, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::Test,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Timer,
        /* .aParams = */ { 0x1388, 0x0, 0x0, 0x0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressUpdateIpAddressDisplay,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x12c, 0xfa, 0xc8, 0x32 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0x12c, 0x10c, 0xd5, 0x14 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::UIMENU_ConnectToServerCallback,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x123, 0x10e, 0xda, 0x1a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_IPAddressBox,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x10c, 0x15e, 0x108, 0xb0 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_PopUpOKCancel2,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x119, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressStartTcpIpTimer,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x1a5, 0x151, 0x60, 0x20 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x13ee,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_CancelButtonBlank,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::UIMENU_ConnectToServerCallback,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x0, 0x60, 0x320, 0x1e },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x143, 0x86, 0x12c, 0x1e },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x10
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x15f, 0x86, 0x1a9, 0x1e },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x0, 0x257, 0xc8, 0x28 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x0, 0x257, 0x320, 0x258 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_downloadpatchbckg,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0x190, 0x12c, 0xcf, 0xac },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_downloadpatchball2,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x150, 0x21c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressCancelTermsOfServiceDownload,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_ImageEx,
        /* .aParams = */ { 0xc3, 0x1a6, 0x19a, 0xf5 },
        /* .nExtraParam = */ 0x4,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_TileableDialog,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x14f, 0x19c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x19f, 0x19c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0xff, 0x19c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xc3, 0xed, 0x19a, 0x28 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xc7, 0x179, 0x192, 0x8c },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x8,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xc7, 0x179, 0x192, 0xb4 },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x8,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont7,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0xfa, 0x15b, 0x12c, 0x1a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_EditTextBoxWide,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0xfa, 0x191, 0x12c, 0x1a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_EditTextBoxWide,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xc8, 0x15e, 0x190, 0x64 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xc8, 0x203, 0x190, 0x64 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xfc, 0x154, 0x12c, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xfc, 0x18a, 0x12c, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0xfd, 0x156, 0x125, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0xfd, 0x18c, 0x125, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x109, 0x20f, 0x110, 0x23 },
        /* .nExtraParam = */ 0xd,
        /* .nLabelAsLocaleStringId = */ 0x2b59,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_Unused19,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x109, 0x23c, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x2b5a,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressConfirmSkipEmailPopup,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x21, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressAcceptEmailAddress,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x0, 0x136, 0x320, 0x32 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x273, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x2b36,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::MAINMENU_Unused21,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x21, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressShowDisconnectedFromBattleNet2Alt2,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x9e, 0x1f4, 0x1e0, 0xdc },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x8,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0xf8, 0x1ab, 0x12c, 0x1a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_EditTextBoxWide,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xfa, 0x1a4, 0x12c, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0xfb, 0x1a6, 0x125, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_Unused21,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0xf8, 0x1dd, 0x12c, 0x1a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_EditTextBoxWide,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xfa, 0x1d6, 0x12c, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0xfb, 0x1d8, 0x125, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_Unused21,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x0, 0x11d, 0x320, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x0, 0x12c, 0x320, 0x10 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x0, 0x181, 0x320, 0x10 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x0, 0x1d6, 0x320, 0x10 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x14f, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x2b2a,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_3WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressChangePassword,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x1a4, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x2b69,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_3WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressShowDisconnectedFromBattleNet,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x108, 0x1f9, 0x110, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x2b6b,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_3WideButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::thunk_UIMENU_YouWereDisconnectedFromBattleNet3,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x21, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressReturnToMainMenuAgain_ForBnetDisconnected2,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x0, 0x136, 0x320, 0x32 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont2,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0x9e, 0x1f4, 0x1e0, 0xdc },
        /* .nExtraParam = */ 0xa,
        /* .nLabelAsLocaleStringId = */ 0x8,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x2
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0xf8, 0x192, 0x12c, 0x1a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_EditTextBoxWide,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xfa, 0x18b, 0x12c, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0xfb, 0x18d, 0x125, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_Unused20,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0xf8, 0x1c4, 0x12c, 0x1a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_EditTextBoxWide,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xfa, 0x1bd, 0x12c, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0xfb, 0x1bf, 0x125, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_Unused20,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0xf8, 0x1f6, 0x12c, 0x1a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_EditTextBoxWide,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xfa, 0x1ef, 0x12c, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0xfb, 0x1f1, 0x125, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_Unused20,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Image,
        /* .aParams = */ { 0xf8, 0x228, 0x12c, 0x1a },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_EditTextBoxWide,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_TextBox,
        /* .aParams = */ { 0xfa, 0x221, 0x12c, 0x20 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x0,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont1,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_EditBox,
        /* .aParams = */ { 0xfb, 0x223, 0x125, 0x13 },
        /* .nExtraParam = */ 0x8,
        /* .nLabelAsLocaleStringId = */ 0x4,
        /* .pDC6 = */ nullptr,
        /* .fpOnPressCallback = */ nullptr,
        /* .pTypeArg1 = */ (void*)&D2Launch::MainMenus::MAINMENU_Unused20,
        /* .pTypeArg2 = */ (void*)gaMenuFormFontParamsFont5,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x273, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x0,
        /* .nLabelAsLocaleStringId = */ 0x2b36,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ (OnPress)&D2Launch::MainMenus::MAINMENU_Unused20,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    },
    {
        /* .neD2FormType = */ FORM_Button,
        /* .aParams = */ { 0x21, 0x23c, 0x80, 0x23 },
        /* .nExtraParam = */ 0x1b,
        /* .nLabelAsLocaleStringId = */ 0x13ef,
        /* .pDC6 = */ (DC6*)&DC6_FrontEnd_MediumButtonBlank,
        /* .fpOnPressCallback = */ &D2Launch::MainMenus::MAINMENU_OnPressShowDisconnectedFromBattleNet2_ForBnetDisconnected3,
        /* .pTypeArg1 = */ nullptr,
        /* .pTypeArg2 = */ nullptr,
        /* .nFlagsOrType = */ 0x0
    }
};

uint8_t gaNewCharDefaultAppearance[16] = {
    0x1,
    0x1,
    0x1,
    0x1,
    0x1,
    0xff,
    0xff,
    0xff,
    0x1,
    0x1,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff,
    0xff
};

D2ControlStrc * FORMS_pListExEx[64] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
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

D2ControlStrc * FORMS_pList[64] = {
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
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

char gszPasswordChangeNewPasswordMB[24] = {
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
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
};

D2ControlStrc * gaAnimImgCharCreateByClass[7] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };

eOogCurrentCharSelectionMode OogCurrentCharSelectionMode = 0;

char gszLastTcpIpAddress[256] = {
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

DC6 * gaDC6CharCreateAssassin[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

DC6 * gaDC6CharCreateDruid[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

DC6 * gaDC6CharCreateAmazon[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

DC6 * gaDC6CharCreateNecromancer[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

DC6 * gaDC6CharCreateBarbarian[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

DC6 * gaDC6CharCreateSorceress[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

DC6 * gaDC6CharCreatePaladin[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

DC6 * gaDC6CharCreateNecromancerSel[3] = { nullptr, nullptr, nullptr };

DC6 * gaDC6CharCreateSorceressSel[3] = { nullptr, nullptr, nullptr };

int gnCharSlotYPositions[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

D2WinTextBox * gaCharSelScreenSlotControls[8] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };

char PreferredClosedRealm[256] = {
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

D2ControlStrc * gaCharSelExpansionIconControls[8] = { nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr };

char PreferedClosedRealm2[256] = {
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

D2SaveFileHeaderStrc SAVEFILE = {
    /* .dwHeader = */ 0,
    /* .dwFileVersion = */ 0,
    /* .nFileSize = */ 0,
    /* .dwChecksum = */ 0,
    /* .bWeaponSwapped = */ 0,
    /* .field5_0x11 = */ 0,
    /* .field6_0x12 = */ 0,
    /* .field7_0x13 = */ 0,
    /* .szCharacterName = */ {
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
    },
    /* .dwCharacterStatus = */ 0,
    /* .nPlayerClassId = */ 0,
    /* .nConst16 = */ 0,
    /* .nMaxSkillsCount = */ 0,
    /* .bCharacterLevel = */ 0,
    /* .nCreateTime = */ 0,
    /* .nTime32 = */ 0,
    /* .nTimeEx = */ 0,
    /* .pHotKeys = */ {
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        },
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        },
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        },
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        },
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        },
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        },
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        },
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        },
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        },
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        },
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        },
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        },
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        },
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        },
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        },
        {
            /* .nSkillIdAndHand = */ 0,
            /* .nItemIndex = */ 0
        }
    },
    /* .pLeftHand = */ {
        /* .nSkillId = */ 0,
        /* .nItemIndex = */ 0
    },
    /* .pRightHand = */ {
        /* .nSkillId = */ 0,
        /* .nItemIndex = */ 0
    },
    /* .pLeftSwapHand = */ {
        /* .nSkillId = */ 0,
        /* .nItemIndex = */ 0
    },
    /* .pRightSwapHand = */ {
        /* .nSkillId = */ 0,
        /* .nItemIndex = */ 0
    },
    /* .pAppearance1 = */ {
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
    },
    /* .pAppearance2 = */ {
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
    },
    /* .pDifficulty = */ { 0, 0, 0 },
    /* .nInitSeed = */ 0,
    /* .nMercFlags = */ 0,
    /* .nMercSeed = */ 0,
    /* .nMercNameId = */ 0,
    /* .nMercType = */ 0,
    /* .nMercExperience = */ 0,
    /* .nMercReserved = */ { 0, 0, 0, 0 },
    /* .nGuildInfo = */ { 0, 0, 0 },
    /* .nReserved = */ {
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
    }
};

// =============================================================================
// Initialized scalars
// =============================================================================

// also labelled: gnClassDescriptionTooltipUnitId
uint32_t gnClassDescriptionTooltipClassId = -0x1;
int gnClassDescriptionTooltipState = -0x1;
int gnCharSelLoadMoreEntryIndex = -0x3e7;
int gnCharSelLoadingEntryIndex = -0x3e7;
int gnCharSelScreenSlotCount = 0x5;
uint32_t gbTermsOfServiceCancelled = 0;
D2ControlStrc * bCharacterCreationInProgress = 0;
// also labelled: gbPasswordChangeInProgress
D2WinEditBox * gpBnetPasswordEditBox = 0;
D2WinTextBox * gpCtlTcpIpConnectAddressLabel = 0;
D2WinTextBox * gpCtlCharCreateBNetRealmTextBox = 0;
D2WinEditBox * gpCtlChangePasswordInput = 0;
D2WinTimer * gpMainMenuTcpIpTimerControl = 0;
// also labelled: gpBNetCharNameInputControl
D2WinButton * gpCtlCreateCharLadderCheckbox = 0;
D2WinEditBox * gpaCharNameBuffers = 0;
D2WinTextBox * gpCtlCreateCharExpClassPanel = 0;
D2WinTextBox * gpCtlTcpIpLocalIpTextBox = 0;
// also labelled: LastKnownIp
D2WinEditBox * gpBnetAccountEditBox = 0;
// also labelled: gnMainMenuUnused8Counter
D2WinTextBox * gpMainMenuGatewayListTextBox = 0;
D2ControlStrc * gpCtlBNetPasswordChangeButton = 0;
D2ControlStrc * gpCtlCreateCharCancelButton = 0;
uint32_t gnTcpIpConnectionSuccessFlag = 0;
D2ControlStrc * gpCtlTcpIpAddressButton = 0;
D2ControlStrc * gpCtlTcpIpConnectButton = 0;
// also labelled: gnMainMenuPasswordChangeBuffer
D2WinEditBox * gpBnetPasswordConfirmEditBox = 0;
D2WinButton * gpCtlRealmNameButton = 0;
// also labelled: pSingleplayerCharacterListTextbox
D2WinTextBox * gpCtlCreateCharHardcoreLabel = 0;
// also labelled: gpCtlCreateCharExpClassButton
D2ControlStrc * gpCtlCreateCharExpansionCheckboxImage = 0;
// also labelled: gpBNetRealmQueryControl
D2WinTextBox * gpCtlCreateCharLadderLabel = 0;
pfnUIMenuInstance gpCurrentUIMenuInstance = (pfnUIMenuInstance)0;
// also labelled: gpSingleplayerCharSelControl
D2ControlStrc * gpCtlCreateCharHardcoreCheckbox = 0;
// also labelled: gnClassCreateClassIndex
D2WinButton * gpCtlCreateCharExpansionCheckbox = 0;
D2WinTextBox * gpCtlCreateCharOKButton = 0;
D2IniConfigStrc * D2IniData_launcher = 0;
D2WinTextBox * gpCtlClassDescriptionTooltipPrimary = 0;
D2WinTextBox * gpCtlClassDescriptionTooltipSecondary = 0;
D2WinTextBox * gpCtlTcpIpAddress = 0;
D2WinTextBox * gpCtlTcpIpPort = 0;
uint32_t gnSelectedCharGameState = 0;
uint32_t gnIsFecharPalette = 0;
uint32_t gnBNetBusyFlag = 0;
DC6 * DC6_FrontEnd_blizno = 0;
DC6 * DC6_FrontEnd_trademark = 0;
DC6 * DC6_FrontEnd_Diablo2 = 0;
DC6 * DC6_FrontEnd_D2logoBlackLeft = 0;
DC6 * DC6_FrontEnd_D2logoFireLeft = 0;
DC6 * DC6_FrontEnd_D2logoBlackRight = 0;
DC6 * DC6_FrontEnd_D2logoFireRight = 0;
DC6 * DC6_FrontEnd_TitleScreen_or_gameselectscreenEXP = 0;
DC6 * DC6_CURSOR_ohand = 0;
DC6 * DC6_CharSelect_creditsbckg = 0;
DC6 * DC6_FrontEnd_CharacterCreate_or_charactercreationscreenEXP = 0;
DC6 * DC6_FrontEnd_fire = 0;
DC6 * DC6_CharSelect_Realmselectbutton = 0;
DC6 * DC6_CharSelect_TallButtonBlank = 0;
DC6 * DC6_CharSelect__characterselectscreenEXP = 0;
DC6 * DC6_FrontEnd_WideButtonBlank = 0;
DC6 * DC6_FrontEnd_MediumButtonBlank = 0;
DC6 * DC6_CharSelect_ShortButtonBlank = 0;
DC6 * DC6_FrontEnd_MediumSelButtonBlank = 0;
DC6 * DC6_FrontEnd_textbox2 = 0;
DC6 * DC6_FrontEnd_3WideButtonBlank = 0;
DC6 * DC6_FrontEnd_EditTextBoxWide = 0;
DC6 * DC6_FrontEnd_WideButtonBlank02 = 0;
DC6 * DC6_FrontEnd_NarrowButtonBlank = 0;
DC6 * DC6_FrontEnd_GWListBox = 0;
DC6 * DC6_FrontEnd_TermsofUseBckg = 0;
DC6 * DC6_CharSelect_charselectbckg = 0;
DC6 * DC6_CharSelect_DifficultyLevels = 0;
DC6 * DC6_FrontEnd_CinematicsSelection = 0;
DC6 * DC6_FrontEnd_CinematicsSelectionEXP = 0;
DC6 * DC6_CharSelect_charselectbox = 0;
DC6 * DC6_CharSelect_charselectboxgrey = 0;
DC6 * DC6_FrontEnd_PopUpOKCancel = 0;
DC6 * DC6_FrontEnd_PopUpOKCancel2 = 0;
DC6 * DC6_CharSelect_selectchararrows = 0;
DC6 * DC6_FrontEnd_CurRealm_or_Realmselect = 0;
DC6 * DC6_FrontEnd_NarrowButtonBlank02_or_RealmSelectbuttonthin = 0;
DC6 * DC6_CharSelect_CreateNewCharImage = 0;
DC6 * DC6_FrontEnd_PopUpOK = 0;
DC6 * DC6_FrontEnd_PopUp_340x224 = 0;
DC6 * DC6_FrontEnd_PopUpWide = 0;
DC6 * DC6_FrontEnd_PopUpLargest = 0;
DC6 * DC6_FrontEnd_TileableDialog = 0;
DC6 * DC6_FrontEnd_PopUpOK2 = 0;
DC6 * DC6_FrontEnd_OkCancelButtonBlank = 0;
DC6 * DC6_FrontEnd_CancelButtonBlank = 0;
DC6 * DC6_CharSelect_password = 0;
DC6 * DC6_FrontEnd_textbox = 0;
DC6 * DC6_FrontEnd_clickbox = 0;
DC6 * DC6_FrontEnd_joingameclickboxgrey = 0;
DC6 * DC6_FrontEnd_realmbckg = 0;
DC6 * DC6_FrontEnd_joingamescrollbars = 0;
DC6 * DC6_FrontEnd_tcpipbckg_or_tcpipscreen = 0;
DC6 * DC6_FrontEnd_IPAddressBox = 0;
DC6 * DC6_FrontEnd_downloadpatchbckg = 0;
DC6 * DC6_FrontEnd_downloadpatchball2 = 0;
DC6 * DC6_FrontEnd_barbarian_bafws = 0;
DC6 * DC6_FrontEnd_paladin_pafws = 0;
uint32_t gbCinematicsMenuShown = 0;
uint32_t fpInsertPlayCd = 0;
int fpLoadAllMediaMpqCallback = 0;
int FORMS_nListExExCount = 0;
int FORMS_nListCount = 0;
uint32_t gbMainMenuUIActive = 0;
D2WinEditBox * gpMainMenuFormPtrs = 0;
// also labelled: gnMainMenuCreditsLineHeights
D2WinTextBox * gpMainMenuCreditsPairLeftTextBox = 0;
// also labelled: gMainMenuCreditScrollOffset
D2WinTextBox * gpMainMenuCreditsPairRightTextBox = 0;
// also labelled: gnMainMenuCreditsLinePositions
D2WinTextBox * gpMainMenuCreditsLineTextBox = 0;
int gnMainMenuCreditsFrameIndex = 0;
uint32_t gnPaletteLoadedFlag = 0;
uint32_t gnMainMenuConnectFlag = 0;
// also labelled: gnPatchProgressValue
D2WinTextBox * gpPatchProgressTextBox = 0;
D2WinImage * gpCtlPatchProgressAnimImage = 0;
uint32_t gbMainMenuShowBNetRealmPanel = 0;
D2BNetRealmEntryStrc * * g_pBNetRealmList = 0;
int gnRealmListCount = 0;
uint32_t gnMCPConnectThreadHandle = 0;
D2ControlStrc * gpCtlBnetProgressBar2 = 0;
D2WinTextBox * gpCtlBnetProgressBar = 0;
D2WinTextBox * gbBnetConnectionTimerActive = 0;
int gbBnetProgressActive = 0;
HANDLE ghBnetConnectHandle = 0;
D2WinEditBox * gpCharSelAccountNameInputControl = 0;
D2WinEditBox * gpCtlDisconnectMessage1 = 0;
D2WinEditBox * gpCtlDisconnectMessage2 = 0;
D2WinEditBox * gpCtlDisconnectMessage3 = 0;
D2WinEditBox * gpnEmailBuffer = 0;
D2WinEditBox * gpCtlEnterEmailInput = 0;
D2ControlStrc * gpCtlEmailConfirmButton = 0;
uint32_t gbEmailAddressScreenReady = 0;
D2WinEditBox * gpCharSelPasswordInputControl = 0;
D2WinEditBox * gpCtlDisconnectDialog = 0;
D2ControlStrc * gpCtlBnetPasswordOkButton = 0;
D2WinTextBox * gpWinTextBoxRealmSelect = 0;
D2ControlStrc * gpCtlRealmSelectionPanel = 0;
D2WinTextBox * gpCharSelDeleteButton = 0;
D2WinButton * gpCtlCharSelDownArrow = 0;
D2ControlStrc * gpCharSelExitButton = 0;
D2WinButton * gpCtlCharSelOKButton = 0;
D2WinTextBox * gpaCharSelectDisplay = 0;
D2ControlStrc * gpCtlCharSelectGameTypeBtn = 0;
D2ControlStrc * gpCtlCharSelDeleteButton = 0;
uint32_t gnCharSelSelectedIndex = 0;
D2WinTextBox * gpCharSelExpansionToggle = 0;
D2ControlStrc * gnCharSelImageOffset = 0;
D2WinImage * gpControlCharSelImage = 0;
D2WinTextBox * gpCtlRealmSelectionLabel = 0;
D2WinButton * gpCharSelScreenControl = 0;
D2WinTextBox * gpCtlCharSelScrollbar = 0;
D2ControlStrc * gnRealmSelectionOffset = 0;
D2WinTextBox * gpControlCharSelList = 0;
D2ControlStrc * gpControlCharSelArrows = 0;
D2WinImage * gpaCharSelCharacterList = 0;
D2ControlStrc * gpControlRealmSelectDropdown = 0;
D2WinTextBox * gpControlRealmSelect = 0;
uint32_t gbCharSelectInProgress = 0;
int nCharacterSelectionIndex = 0;
uint32_t gnCharSelBNetLoadState = 0;
// also labelled: gpPendingRealmArchive
char * gszPendingRealmName = 0;
char gbCharSelScreenWaitTimeout = 0;
uint32_t gbCharSelArrowsHidden = 0;
D2CharSelStrc * gpCharSelPendingEntry = 0;
int32_t g_nCharSelNavigationIndex = 0;
uint32_t gpCharSelScrollbar = 0;
D2WinTextBox * gpCharSelStatusTextBox = 0;
D2WinTextBox * gnCharSelScrollOffset = 0;
uint32_t gnCharSelLoadedCharCount = 0;
uint32_t gnCharSelCreateNewButtonClickCount = 0;
D2RealmCharListCacheEntryStrc * gpRealmCharListCache = 0;
D2BNetClientCallbacksStrc * gpBNetCallbacks = 0;
uint32_t gnBusyFlag = 0;
uint32_t gbLauncherBnetConnectInProgress = 0;

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

} // namespace D2Game::GAME::Event::Dispatch

namespace D2Game::GAME::Event::Dispatch::Player {

} // namespace D2Game::GAME::Event::Dispatch::Player

namespace D2Game::GAME::Event::Dispatch::Object {

} // namespace D2Game::GAME::Event::Dispatch::Object

namespace D2Game::GAME::Event::Dispatch::Monster {

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

// =============================================================================
// Initialized scalars
// =============================================================================

uint32_t nSelectedCharIndex = -0x1;
D2CharSelStrc * D2CharSelStrcFirst = 0;
uint32_t TotalCurrentChars = 0;

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

} // namespace D2Game::Quests::QUESTS::Quest40

namespace D2Game::Quests::QUESTS::A5Q1 {

} // namespace D2Game::Quests::QUESTS::A5Q1

namespace D2Game::Quests::QUESTS::A5Q2 {

} // namespace D2Game::Quests::QUESTS::A5Q2

namespace D2Game::Quests::QUESTS::A5Q3 {

} // namespace D2Game::Quests::QUESTS::A5Q3

namespace D2Game::Quests::QUESTS::A5Q4 {

} // namespace D2Game::Quests::QUESTS::A5Q4

namespace D2Game::Quests::QUESTS::A5Q5 {

} // namespace D2Game::Quests::QUESTS::A5Q5

namespace D2Game::Quests::QUESTS::A5Q6 {

} // namespace D2Game::Quests::QUESTS::A5Q6

namespace D2Game::Quests::QUESTS::Quest37 {

} // namespace D2Game::Quests::QUESTS::Quest37

namespace D2Game::Quests::QUESTS::A1Q0 {

} // namespace D2Game::Quests::QUESTS::A1Q0

namespace D2Game::Quests::QUESTS::A1Q1 {

} // namespace D2Game::Quests::QUESTS::A1Q1

namespace D2Game::Quests::QUESTS::A1Q2 {

} // namespace D2Game::Quests::QUESTS::A1Q2

namespace D2Game::Quests::QUESTS::A1Q3 {

} // namespace D2Game::Quests::QUESTS::A1Q3

namespace D2Game::Quests::QUESTS::A1Q4 {

} // namespace D2Game::Quests::QUESTS::A1Q4

namespace D2Game::Quests::QUESTS::A1Q5 {

} // namespace D2Game::Quests::QUESTS::A1Q5

namespace D2Game::Quests::QUESTS::A1Q6 {

} // namespace D2Game::Quests::QUESTS::A1Q6

namespace D2Game::Quests::QUESTS::A1Q7 {

} // namespace D2Game::Quests::QUESTS::A1Q7

namespace D2Game::Quests::QUESTS::Quest38 {

} // namespace D2Game::Quests::QUESTS::Quest38

namespace D2Game::Quests::QUESTS::A2Q0 {

} // namespace D2Game::Quests::QUESTS::A2Q0

namespace D2Game::Quests::QUESTS::A2Q1 {

} // namespace D2Game::Quests::QUESTS::A2Q1

namespace D2Game::Quests::QUESTS::A2Q2 {

} // namespace D2Game::Quests::QUESTS::A2Q2

namespace D2Game::Quests::QUESTS::A2Q3 {

} // namespace D2Game::Quests::QUESTS::A2Q3

namespace D2Game::Quests::QUESTS::A2Q4 {

} // namespace D2Game::Quests::QUESTS::A2Q4

namespace D2Game::Quests::QUESTS::A2Q5 {

} // namespace D2Game::Quests::QUESTS::A2Q5

namespace D2Game::Quests::QUESTS::A2Q6 {

} // namespace D2Game::Quests::QUESTS::A2Q6

namespace D2Game::Quests::QUESTS::A2Q7 {

} // namespace D2Game::Quests::QUESTS::A2Q7

namespace D2Game::Quests::QUESTS::A2Q8 {

} // namespace D2Game::Quests::QUESTS::A2Q8

namespace D2Common::Monsters::MONSTERS::Umod {

} // namespace D2Common::Monsters::MONSTERS::Umod

namespace D2Game::Quests::QUESTS::A4Q0 {

} // namespace D2Game::Quests::QUESTS::A4Q0

namespace D2Game::Quests::QUESTS::A4Q1 {

} // namespace D2Game::Quests::QUESTS::A4Q1

namespace D2Game::Quests::QUESTS::A4Q2 {

} // namespace D2Game::Quests::QUESTS::A4Q2

namespace D2Game::Quests::QUESTS::A4Q3 {

} // namespace D2Game::Quests::QUESTS::A4Q3

namespace D2Game::Quests::QUESTS::A4Q4 {

} // namespace D2Game::Quests::QUESTS::A4Q4

namespace D2Game::Quests::QUESTS::Quest39 {

} // namespace D2Game::Quests::QUESTS::Quest39

namespace D2Game::Quests::QUESTS::A3Q0 {

} // namespace D2Game::Quests::QUESTS::A3Q0

namespace D2Game::Quests::QUESTS::A3Q1 {

} // namespace D2Game::Quests::QUESTS::A3Q1

namespace D2Game::Quests::QUESTS::A3Q2 {

} // namespace D2Game::Quests::QUESTS::A3Q2

namespace D2Game::Quests::QUESTS::A3Q3 {

} // namespace D2Game::Quests::QUESTS::A3Q3

namespace D2Game::Quests::QUESTS::A3Q4 {

} // namespace D2Game::Quests::QUESTS::A3Q4

namespace D2Game::Quests::QUESTS::A3Q5 {

} // namespace D2Game::Quests::QUESTS::A3Q5

namespace D2Game::Quests::QUESTS::A3Q6 {

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
// 0x0070cc4c and 0x0077abf4. Their only reader is ShowOogErrorDialog 0043b9f0, whose
// OOG_ERROR_BNET_ACCOUNT_CHECK arm was one of the arms the generator dropped, so the
// globals were never emitted either. gnBnetAccountLoginFailCount starts at 1 in the image.
int gnBnetAccountLoginFailCount = 1;
char gszOogLastIniStringCache[16] = {};
