//
//  JCLocalVideoController.m
//  TORNADO EYES
//
//  Created by yingyi on 15/8/18.
//  Copyright (c) 2015年 im360 immersive. All rights reserved.
//

#import "JCLocalVideoController.h"
#import "UIView+Extension.h"
#import "JCPlayPauseView.h"
#import "JCMideoModeView.h"
#import "JCConst.h"

@interface JCLocalVideoController () <JCPlayPauseViewDelegate,JCMideoModeViewDelegate>
/** 播放暂停栏 */
@property (nonatomic ,weak)JCPlayPauseView *toolbar;
/** 观看模式栏，导航栏上 */
@property (nonatomic ,weak)UISegmentedControl *segmentView;
/** 播放模式栏 */
@property (nonatomic ,weak)JCMideoModeView *modeView;
- (void)playerInitialized:(id)sender;
@end

@implementation JCLocalVideoController

class PlayerProxy : public im360::event::EventListener   //EventListener
{
public:
    typedef core::SharedPointer<PlayerProxy>::pointer pointer;
    
    PlayerProxy() : EventListener()
    {
        
    }
    
    virtual ~PlayerProxy()
    {
        
    }
    
    void onEvent(event::Event::pointer event)
    {
        if( event->getPointer<im360::event::MediaEvent>() ) [owner onMediaPlayStateChange:event->getPointer<im360::event::MediaEvent>()];
        else if( event->getPointer<im360::event::TimeChangeEvent>() ) [owner onMediaTimeChange:event->getPointer<im360::event::TimeChangeEvent>()];
    }
    
    JCLocalVideoController* owner;
};

class MediaData
{
public:
    MediaData()
    {
        playerProxy = PlayerProxy::pointer(new PlayerProxy());
    }
    
    PlayerProxy::pointer playerProxy;
    
};

#define MEDIADATA (*((MediaData*)_mediaData))

- (void)onMediaPlayStateChange:(im360::event::MediaEvent::pointer)event
{
    if (event->getEventId() == event->MEDIA_LOADED){
        // Media has loaded fully
//        NSLog(@"MEDIA_LOADED");
    }
    if (event->getEventId() == event->MEDIA_ENDED){
        // Media has ended. For example, the video has played all the way through.
//        NSLog(@"media ended");
    }
}
- (void)onMediaTimeChange:(im360::event::TimeChangeEvent::pointer)event
{
    
    if (!_player) return;
    
    im360::scene::BasicScene::pointer scene = _player->getScene<im360::scene::BasicScene>();
    if( !scene ) return;
    
    // Percent of video played
    
    float percent =  event->time / scene->getDuration() ;
    // Can be used to update a playbar timeline
//    NSLog([NSString stringWithFormat:@"%1.6f", percent]);
    self.toolbar.progressBarView.value = percent;
    
}


#pragma mark - 界面搭建
- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self setnavUp];
    
    [self setupToolbar];
    
    [self setupLookMode];
    
}
-(void)setnavUp
{
    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"返回" style:UIBarButtonItemStyleDone target:self action:@selector(cancel)];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle:@"模式" style:UIBarButtonItemStyleDone target:self action:@selector(tabarIsHidden)];
    UISegmentedControl *segmentView = [[UISegmentedControl alloc]initWithFrame:CGRectMake(0, 0, 100, 40)];
    [segmentView insertSegmentWithTitle:@"MOTION" atIndex:0 animated:YES];
    [segmentView insertSegmentWithTitle:@"FINGER" atIndex:1 animated:YES];
//    segmentView.backgroundColor = [UIColor redColor];
    segmentView.selectedSegmentIndex = 0;
    self.navigationItem.titleView = segmentView;
    self.segmentView = segmentView;
    [segmentView addTarget:self action:@selector(controlPressed) forControlEvents:UIControlEventValueChanged];
  
}
//观看模式
-(void)controlPressed
{
    if( !_player) return;
    scene::BasicScene::pointer scene = _player->getScene<scene::BasicScene>();
    if( !scene )
    {
        NSLog(@"!scene");
        return;
    }
    int selecteIndex = self.segmentView.selectedSegmentIndex;
    if (selecteIndex == 0) {

        scene->setLookFlags(im360::scene::BasicScene::LM_FINGER | im360::scene::BasicScene::LM_GRAVITY | im360::scene::BasicScene::LM_MOTION);
    }else{
        scene->setLookFlags(im360::scene::BasicScene::LM_FINGER);
    }
    NSLog(@"LookFlags %d",scene->getLookFlags());
}

-(void)setupLookMode
{
    JCMideoModeView *modeView = [[JCMideoModeView alloc]init];
    modeView.height = 45;
    modeView.width= self.view.width;
    modeView.x = 0;
    modeView.y = self.view.height - modeView.height;
    modeView.delegate = self;
    [self.view addSubview:modeView];
    modeView.hidden = YES;
    self.modeView = modeView;
    
}
-(void)tabarIsHidden
{
//    self.toolbar.hidden = !self.toolbar.isHidden;
    self.modeView.hidden = !self.modeView.isHidden;
    
}

-(void)setupToolbar
{
    JCPlayPauseView *toolbar = [[JCPlayPauseView alloc]init ];
    toolbar.width = self.view.width;
    toolbar.height = 44;
    toolbar.y = self.view.height - toolbar.height;
    toolbar.x = 0;
    toolbar.delegate = self;
    [self.view addSubview:toolbar];
    self.toolbar = toolbar;
}

#pragma mark - 其它方法 -
-(void)cancel
{
    [_im360View stopAnimation];
    [self dismissViewControllerAnimated:YES completion:nil];
}
-(void)viewDidAppear:(BOOL)animated
{
    CGRect rect = self.view.frame;

    if( self.interfaceOrientation == UIInterfaceOrientationLandscapeLeft || self.interfaceOrientation == UIInterfaceOrientationLandscapeRight )
    {
        
        _im360View = [[IM360View alloc] initWithFrame:rect];

    }else{
        CGFloat im360ViewY = self.view.size.height * 0.25 ;
        _im360View = [[IM360View alloc] initWithFrame:CGRectMake(self.view.origin.x, im360ViewY, self.view.size.width, self.view.size.height * 0.5)];
    }
    _im360View.im360ViewDelegate = self;
    
    [self.view addSubview:_im360View];
    
    [_im360View startAnimation];
    
}
//设备的方向发生改变

- (void)orientationChanged:(NSNotification *)notification
{
    
    UIInterfaceOrientation o = [[UIApplication sharedApplication] statusBarOrientation];
    CGFloat angle = 0;
    switch (o) {
        case UIDeviceOrientationLandscapeLeft: angle = 90; break;
        case UIDeviceOrientationLandscapeRight: angle = -90; break;
        case UIDeviceOrientationPortraitUpsideDown: angle = 180; break;
        default: break;
    }
    
    CGRect f = [[UIScreen mainScreen] applicationFrame];
    
    // Swap the frame height and width if necessary
    if (UIDeviceOrientationIsLandscape(o)) {
        CGFloat t;
        t = f.size.width;
        f.size.width = f.size.height;
        f.size.height = t;
    }
    
    CGAffineTransform previousTransform = self.view.layer.affineTransform;
    CGAffineTransform newTransform = CGAffineTransformMakeRotation((CGFloat)(angle * M_PI / 180.0));
    
    // Reset the transform so we can set the size
    self.view.layer.affineTransform = CGAffineTransformIdentity;
    self.view.frame = (CGRect){ { 0, 0 }, f.size};
    
    // Revert to the previous transform for correct animation
    self.view.layer.affineTransform = previousTransform;
    
    [UIView beginAnimations:nil context:NULL];
    [UIView setAnimationDuration:0.3];
    
    // Set the new transform
    self.view.layer.affineTransform = newTransform;
    
    // Fix the view origin
    self.view.frame = (CGRect){ { f.origin.x, f.origin.y },self.view.frame.size};
    [UIView commitAnimations];
}
//获取当前播放的时间
-(CGFloat)getTimeOfVideo
{
    if( !_player) return 0;
    scene::BasicScene::pointer scene = _player->getScene<scene::BasicScene>();
    if( !scene ) return 0;
    CGFloat playTime = scene->getTime();
//    CGFloat durationTime = scene->getDuration();
//    NSLog(@"playTime:%0.2f",playTime);
    return  playTime;
}
//设置当前的播放时间
-(void)setTimeOfVideo
{
    NSLog(@"setTimeOfVideo");
    if( !_player) return;
    scene::BasicScene::pointer scene = _player->getScene<scene::BasicScene>();
    if( !scene ) return;
    CGFloat timeValue = self.toolbar.progressBarView.value * scene->getDuration();
    NSInteger intTimeValue = ceilf(timeValue);
    scene->setTime(intTimeValue);
}
-(void)starPlay
{
    if (_starTimer) return;
    _starTimer = [NSTimer scheduledTimerWithTimeInterval:1.0/3.0 target:self selector:@selector(getTimeOfVideo) userInfo:nil repeats:YES];
}
-(void)stopPlay
{
    if (!_starTimer) return;
    [_starTimer invalidate];
    _starTimer = nil;
}
//设置暂停和播放
- (void)setPlaybarBtnStates
{
    if( !_player) return;
    scene::BasicScene::pointer scene = _player->getScene<scene::BasicScene>();
    if( !scene ) return;
    //    _rewindBtn.enabled = scene->getTime()>0;
    if( scene->getPaused() /*&& _playbar.items!=_playbarItemsPlay */)
    {

        scene->setPaused(NO);
        [self.toolbar.playPauseBtn setImage:[UIImage imageNamed:@"moviePause@2x.png"] forState:UIControlStateNormal];
        //        [_playbar setItems:_playbarItemsPlay animated:NO];
    }
    else if( !scene->getPaused() /* && _playbar.items!=_playbarItemsPause */)
    {
        [self getTimeOfVideo];
        scene->setPaused(YES);
        [self.toolbar.playPauseBtn setImage:[UIImage imageNamed:@"moviePlay@2x.png"] forState:UIControlStateNormal];
        //        [_playbar setItems:_playbarItemsPause animated:NO];
    }
    
}

-(void)viewDidDisappear:(BOOL)animated
{
    [_im360View stopAnimation];
}

-(BOOL)shouldAutorotate
{
    return NO;
}

- (NSUInteger)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskLandscapeLeft;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationLandscapeLeft ||
            
            interfaceOrientation == UIInterfaceOrientationLandscapeRight );
}

-(void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
    //控制导航栏的显示和隐藏

    [self navigationController].navigationBarHidden = ![self navigationController].isNavigationBarHidden;
    self.toolbar.hidden = [self navigationController].navigationBarHidden;
    self.modeView.hidden = YES;
}


- (void)playerInitialized:(id)sender
{
//    NSLog(@"playerInitialized");
    
    _player = _im360View.player;
    if( self.interfaceOrientation == UIInterfaceOrientationLandscapeLeft ){
        [_im360View setOrientation:UIInterfaceOrientationLandscapeLeft];
    }
    if (self.interfaceOrientation == UIInterfaceOrientationLandscapeRight ) {
       [_im360View setOrientation:UIInterfaceOrientationLandscapeRight];
    }
    if (self.interfaceOrientation == UIDeviceOrientationPortrait ) {
        [_im360View setOrientation:UIDeviceOrientationPortrait];
    }
    if (self.interfaceOrientation == UIDeviceOrientationPortraitUpsideDown ) {
        [_im360View setOrientation:UIDeviceOrientationPortraitUpsideDown];
    }
//    [_im360View setOrientation:UIInterfaceOrientationLandscapeLeft];
    im360::scene::BasicScene::pointer scene = _player->getScene<im360::scene::BasicScene>();
    
    //加上这句程序会报错，卡住
//    scene->resetScene();
    
    
    _mediaData = new MediaData();
    MEDIADATA.playerProxy->owner = self;
    _player->addEventListener(MEDIADATA.playerProxy);
    
    
    if ([self.videoURL isEqual: @""]) {
//        std::string videoURL = [[[NSBundle mainBundle]pathForResource:@"Bay.Bridge.Flying.Pass.2_11031_1280x506_f12_2M_a0.webm" ofType:nil]UTF8String];
//        std::string audeoURL = [[[NSBundle mainBundle]pathForResource:@"Bay.Bridge.Flying.Pass.2.mp3" ofType:nil]UTF8String];
//        scene->loadVideo(videoURL,audeoURL);
    }else{
        std::string videoURL = [self.videoURL UTF8String];
        scene->loadVideo(videoURL);
    }
//    std::string audeoURL = [self.audeoURL UTF8String];
//    NSLog(@"%s",videoURL.c_str());
    //    std::string videoURL1 = [@"http://101.231.87.94:8888/images/1.mp4" UTF8String];
    //    std::string videoURL = [[[NSBundle mainBundle]pathForResource:@"Bay.Bridge.Flying.Pass.2_11031_1280x506_f12_2M_a0.webm" ofType:nil]UTF8String];
    //    std::string audeoURL = [[[NSBundle mainBundle]pathForResource:@"Bay.Bridge.Flying.Pass.2.mp3" ofType:nil]UTF8String];


    scene->setLoopEnabled(FALSE);
    
    //设置logo图标，需要授权许可
    /**
     std::string logourl = [[[NSBundle mainBundle]pathForResource:@"icon@2x.png" ofType:nil]UTF8String];
    scene->setLogoImage(logourl); // requires license
    NSLog(@"%d",scene->setLogoImage(logourl));
    */
     //不让手机锁屏
    [[UIApplication sharedApplication] setIdleTimerDisabled:YES];
    
    [self setupToolbar];
    [self setupLookMode];
    
    [self starPlay];
    [[NSNotificationCenter defaultCenter]addObserver:self selector:@selector(setTimeOfVideo) name:sliderValueChange object:nil];
}
-(void)dealloc
{
    [[NSNotificationCenter defaultCenter]removeObserver:self];
}
#pragma mark - JCPlayPauseDelegate
-(void)JCPlayPauseView:(JCPlayPauseView *)toolbar didClickButton:(JCPlayPauseViewButtonType)buttonType
{
    
    switch (buttonType) {
        case JCPlayPauseViewButtonTypeBackward:
            NSLog(@"JCPlayPauseViewButtonTypeBackward");
            
            break;
        case JCPlayPauseViewButtonTypePlayPause:
            [self setPlaybarBtnStates];
            break;
        case JCPlayPauseViewButtonTypeForward:
            NSLog(@"JCPlayPauseViewButtonTypeForward");
            break;
            
        default:
            break;
    }
}
#pragma mark - JJCMideoModeViewDelegate
-(void)JCMideoModeView:(JCMideoModeView *)toolbar didClickButton:(JCMideoModeType)buttonType
{
    _player = _im360View.player;
    switch (buttonType) {
        case JCMideoModeTypeStandard:
            _player->setViewMode(im360::player::PlayerViewMode::STANDARD);
            break;
        case JCMideoModeTypeIs3DSide:
            _player->setViewMode(im360::player::PlayerViewMode::SIDE_BY_SIDE_3D);
            break;
        case JCMideoModeTypeCancel:
            self.modeView.hidden = YES;
            break;
        default:
            break;
    }
}

@end
