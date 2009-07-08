#pragma once
#include "OutlineItemInterop.h"
#include "SearchResultInterop.h"
#include "PageLinksInterop.h"
class AFPDFDocInterop 
{
private:
	void *_ptr;
	SearchResultInterop *_resultsPtr;
	PageLinksInterop _pageLinks;
public:
	AFPDFDocInterop();
	virtual ~AFPDFDocInterop();
	long LoadFromFile(char * sFileName);
	long RenderPage(long lhWnd);
	long GetCurrentPage(void);
	void SetCurrentPage(long newVal);
	
	void ZoomIN();
	void ZoomOUT();
	
	void NextPage();
	void PreviousPage();

	long GetCurrentX(void);
	void SetCurrentX(long newVal);
	long GetCurrentY(void);
	void SetCurrentY(long newVal);

	long RenderBitmap(long lhWnd);
	long GetPageCount(void);
	
	long FitScreenWidth(long lhWnd);
	long FitScreenHeight(long lhWnd);
	long GetPageWidth(void);
	long GetPageHeight(void);
	long GetOutlineCount(void);
	long GetOutlinePtr(long iOutline);
	long ProcessLinkAction(long lPtrLinkAction);
	PageLinksInterop *getPageLinksInterop(long iPage);

	void Dispose();

	float GetRenderDPI(void);
	void SetRenderDPI(float newVal);
	wchar_t *GetPDFVersion(void);
	
	long FindString(const char *sText, long iPage, long SearchOrder, bool bCaseSensitive, bool bBackward, bool bMarkAll, bool bWholeDoc);
	long FindNext(const char *sText);
	long FindPrior(const char *sText);
	long FindFirst(const char *sText, long SearchOrder, bool Backward);
	long RenderHDC(long lHdc);


	long GetSearchPage(void);
	long SetSearchPage(long lNewValue);
	bool GetSearchCaseSensitive(void);
	void SetSearchCaseSensitive(bool newVal);
	double GetZoom();
	void SetZoom(double newValue);
	long PrintToFile(const char *fileName,int fromPage,int toPage);

	SearchResultInterop *GetSearchResults();
	long GetSearchCount();

	void cvtUserToDev(double ux, double uy, int *dx, int *dy);
	void cvtDevToUser(double ux, double uy, double *dx, double *dy);

	char *GetTitle();
	char *GetAuthor();
};
