#include "Common.h"



class CMyWnd
{
public:
	xcgui::XWnd m_Wnd;
	xcgui::XBtn m_btn;

	xcgui::XShapeText m_ShapeText1;
	xcgui::XShapeText m_ShapeText2;
	xcgui::XShapeText m_ShapeText3;
	
    BOOL Create() //创建窗口和按钮
    {
        m_Wnd.Create(0,0,400,300,L"炫彩界面库-窗口"); //创建窗口
        if(m_Wnd)
        {
            m_btn.Create(10,10,80,25,L"按钮",m_Wnd); //创建按钮
            XEle_RegEventCPP(m_btn,XE_BNCLICK,&CMyWnd::OnEventBtnClick); //注册按钮点击事件
		
			
			m_ShapeText1.Create(10,50,100,20,L"测试1",m_Wnd);
			m_ShapeText2.Create(10,80,100,20,L"测试2",m_Wnd);
			m_ShapeText3.Create(10,110,100,20,L"测试3",m_Wnd);


			m_Wnd.ShowWindow(SW_SHOW);  //显示窗口
            return TRUE;
        }
        return FALSE;
    }
    int OnEventBtnClick(BOOL *pBool) //按钮点击事件响应
    {
        //这里是重点 炫彩采用的 用户主动刷新机制
		//这样可以节省效率，因为没刷新一次，内部就必须
		//拷贝一次画好的数据到窗口，大家可以看下面的注释
		//代码，我设置一次文本就调用刷新一次，这样相当于
		//在内存拷贝了三次，效率极其的低下，如果，我设置了
		//只刷新一次，那么将大大的提高了效率

		m_ShapeText1.SetText(L"炫彩界面库");
		m_ShapeText2.SetText(L"xcgui");
		m_ShapeText3.SetText(L"xcgui1");
		m_Wnd.RedrawWnd();
       

// 		m_ShapeText1.SetText(m_hRichEdit,L"炫彩界面库");
// 		m_Wnd.RedrawWnd();
// 		m_ShapeText2.SetText(m_hShapeText,L"xcgui");
// 		m_Wnd.RedrawWnd();
// 		m_ShapeText3.SetText(m_hShapeText1,L"xcgui1");
// 		m_Wnd.RedrawWnd();


		//补充知识。炫彩采用的双缓冲，局部刷新，用户主动刷新
		//等等技术来提高效率

		//比如 改变了一个 基础元素 HELE 那么你只需要调用 
		//XEle_RedrawEle 来刷新这个部位，即可立刻显示
		//刷新局部能大大的提高程序效率
		//了解了这些之后，大家只要遇到 设置了文本或者修改了
		//其他属性不会立刻改变，需要拖动窗口或者激活窗口
		//才会生效 这些问题大家就知道该怎么做了



        *pBool=TRUE; //对该事件进行拦截
        return 0;    //事件的返回值
    }
};

int APIENTRY _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI(); //初始化
    CMyWnd  MyWnd;
    if(MyWnd.Create())
    {
        XRunXCGUI(); //运行
    }
    XExitXCGUI(); //释放资源
    return 0;
}




