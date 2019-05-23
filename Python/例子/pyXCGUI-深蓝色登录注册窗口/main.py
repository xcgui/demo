from xcgui import *

XInitXCGUI("") #初始化UI库
XPy_Init()  #初始化UI库Py支持

hWindow =0
hLayoutContent=0
hCurPanel=0

def SwitchTab(strTy):
    global hCurPanel
    if hCurPanel:
        XEle_Destroy(hCurPanel)
    if "登陆"==strTy:
        hCurPanel = XC_LoadLayout("panel-login.xml",hLayoutContent)
        XEle_SetTextColor(XC_GetObjectByName("登陆"),0xFFFFFF,255)
        XEle_SetTextColor(XC_GetObjectByName("注册"),0x000000,255)
    else:
        hCurPanel = XC_LoadLayout("panel-reg.xml",hLayoutContent)
        XEle_SetTextColor(XC_GetObjectByName("登陆"),0x000000,255)
        XEle_SetTextColor(XC_GetObjectByName("注册"),0xFFFFFF,255)
    XWnd_AdjustLayout(hWindow)
    XWnd_RedrawWnd(hWindow, 0)

def OnBtnCheck_login(bCheck, pbHandled):
    if bCheck:
        print("login ",bCheck)
        SwitchTab("登陆")

def OnBtnCheck_register(bCheck, pbHandled):
    if bCheck:
        print("register ",bCheck)
        SwitchTab("注册")

XC_LoadResource("resource.res") 
hWindow = XC_LoadLayout("main.xml",0) #创建窗口

hLayoutContent =XC_GetObjectByName("content")
SwitchTab("登陆")

XEle_RegEvent(XC_GetObjectByName("登陆"), XE_BUTTON_CHECK, OnBtnCheck_login)
XEle_RegEvent(XC_GetObjectByName("注册"), XE_BUTTON_CHECK, OnBtnCheck_register)

XWnd_AdjustLayout(hWindow)
XWnd_ShowWindow(hWindow, SW_SHOW) #显示窗口

XRunXCGUI() #运行
XExitXCGUI() #释放
