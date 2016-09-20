#include "AppDelegate.h"
#include "SplashScene.h"

USING_NS_CC;

typedef struct tagResource
{
	cocos2d::CCSize size;
	char directory[100];
}Resource;

/*static cocos2d::Size designResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size smallResolutionSize = cocos2d::Size(480, 320);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(960, 640);
static cocos2d::Size largeResolutionSize = cocos2d::Size(1024, 768);
*/

static Resource smallResource = { cocos2d::CCSizeMake(480, 320), "res/HDR" };
static Resource mediumResource = { cocos2d::CCSizeMake(1024, 768), "res/HD" };
static Resource largeResource = { cocos2d::CCSizeMake(2048, 1536), "res/HDR" };
static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(480, 320);

void AppDelegate::initMultiResolution()
{
	CCDirector* pDirector = CCDirector::sharedDirector();
	CCEGLView* pEGLView = Director::sharedDirector()->getOpenGLView();

	pDirector->setOpenGLView(pEGLView);

	// Set the design resolution
	pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);

	CCSize frameSize = pEGLView->getFrameSize();

	std::vector<std::string> _searchPath;

	// if the frame's height is larger than the height of medium resource size, select large resource.
	if (frameSize.height > mediumResource.size.height)
	{
		_searchPath.push_back(largeResource.directory);
		pDirector->setContentScaleFactor(largeResource.size.height / designResolutionSize.height);
	}
	// if the frame's height is larger than the height of small resource size, select medium resource.
	else if (frameSize.height > smallResource.size.height)
	{
		_searchPath.push_back(mediumResource.directory);
		pDirector->setContentScaleFactor(mediumResource.size.height / designResolutionSize.height);
	}
	// if the frame's height is smaller than the height of medium resource size, select small resource.
	else
	{
		_searchPath.push_back(smallResource.directory);
		pDirector->setContentScaleFactor(smallResource.size.height / designResolutionSize.height);
	}

	//pDirector->setContentScaleFactor(scaleFactor);
	FileUtils::getInstance()->setSearchPaths(_searchPath);
}


void AppDelegate::initGLContextAttrs()
{
	//set OpenGL context attributions,now can only set six attributions:
	//red,green,blue,alpha,depth,stencil
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };
	GLView::setGLContextAttrs(glContextAttrs);
}


bool AppDelegate::applicationDidFinishLaunching()
{
	initOpenGL();
	initDirector();
	initMultiResolution();
	createAndRunScene();
	return true;
}


void AppDelegate::initOpenGL()
{
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	if (!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
		glview = GLViewImpl::createWithRect("2", Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
#else
		glview = GLViewImpl::create("2");
#endif
		director->setOpenGLView(glview);
	}
}


void AppDelegate::initDirector()
{
	auto director = Director::getInstance();
	director->setAnimationInterval(1.0 / 60);
	director->setDisplayStats(true);
}


void AppDelegate::createAndRunScene()
{
	auto scene = SplashScene::createScene();
	Director::getInstance()->runWithScene(scene);
}


void AppDelegate::applicationDidEnterBackground()
{
	Director::getInstance()->stopAnimation();
	// SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}


void AppDelegate::applicationWillEnterForeground()
{
	Director::getInstance()->startAnimation();
	// SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}