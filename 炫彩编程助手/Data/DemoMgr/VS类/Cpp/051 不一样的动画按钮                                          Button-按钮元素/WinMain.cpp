#include "Common.h"

class XCImage
{
public:
	XCImage()
	{
		m_imageArray = NULL;
	}
	~XCImage()
	{
		UnLoad();
	}
	void UnLoad()
	{
		if (m_imageArray)
		{
			delete[] m_imageArray;
			m_imageArray = NULL;
		}
	}
	void Load(const wchar_t* imageFile,int ImageCount,int imageWidth,int imageHeight)
	{
		UnLoad();
		m_imageCount = ImageCount;
		int x = 0;
		m_imageArray = new HIMAGE[ImageCount];
		for (int i = 0 ; i < ImageCount; i++)
		{
			m_imageArray[i] = XImage_LoadFileRect(imageFile,x,0,imageWidth,imageHeight);
			x += imageWidth;
		}
	}
	HIMAGE operator[](int index)
	{
		return m_imageArray[index];
	}
	int GetImageCount()
	{
		return m_imageCount;
	}
private:
	HIMAGE* m_imageArray;
	int     m_imageCount;
};

class XCButtonAnimate
{
public:
#define TIMER_ANIMATE_STAY 100
#define TIMER_ANIMATE_LEAVE 101

	XCButtonAnimate()
	{
	}
	void Create(int x,int y,int cx,int cy,HXCGUI hParent)
	{

		m_btnAnimate.Create(100, 50, 95, 95,L"", hParent);

		m_btnAnimate.EnableBkTransparent(TRUE);
		m_btnAnimate.EnableDrawFocus(FALSE);
		m_btnAnimate.AddBkImage(button_state_leave,XImage_LoadFile(L"image\\clean.png"));


		XCImage image;
		image.Load(L"image\\qinglilaji_yijianqingli_Anima_Hover.png",10,95,95);
		for (int i = 0; i < 10; i++)
		{
			m_btnAnimate.AddAnimationFrame(image[i],50);
		}
		XEle_RegEventCPP(m_btnAnimate,XE_MOUSESTAY,&XCButtonAnimate::OnMouseStay);
		XEle_RegEventCPP(m_btnAnimate,XE_MOUSELEAVE,&XCButtonAnimate::OnMouseLeave);

	}

	int OnMouseStay(BOOL *pbHandled)
	{
		m_btnAnimate.EnableAnimation(TRUE);
		return 0;
	}
	int OnMouseLeave(HELE hEleStay,BOOL *pbHandled)
	{
		m_btnAnimate.EnableAnimation(TRUE);

		return 0;
	}
private:
	xcgui::XBtn m_btnAnimate;
	HWINDOW m_hWindow;
};

class CWindow
{
public:
	xcgui::XWnd m_Wnd;
    XCButtonAnimate m_AnimateButton;
	
    CWindow(){
        Init();
    }
    void Init()
    {
		m_Wnd.Create(0, 0, 500, 400, L"ìÅ²Ê½çÃæ¿â´°¿Ú");
		xcgui::XBtn m_btn(10, 5, 60, 20,L"close",m_Wnd);
		m_btn.SetType(button_type_close);
		
		m_AnimateButton.Create(100,100,95,95,m_Wnd);
        m_Wnd.ShowWindow(SW_SHOW);
    }
};

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    XInitXCGUI();
    CWindow  MyWindow;
    XRunXCGUI();
    XExitXCGUI();
    return 0;
}




