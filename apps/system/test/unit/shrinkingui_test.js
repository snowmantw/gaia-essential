'use strict';

mocha.globals(['removeEventListener', 'addEventListener',
      'dispatchEvent', 'WindowManager', 'Applications', 'ManifestHelper',
      'KeyboardManager', 'StatusBar', 'HomescreenWindow',
      'SoftwareButtonManager', 'AttentionScreen', 'AppWindow',
      'LockScreen', 'OrientationManager', 'BrowserFrame',
      'BrowserConfigHelper', 'System', 'BrowserMixin', 'TransitionMixin',
      'ShrinkingUI']);

requireApp('system/shared/test/unit/mocks/mock_manifest_helper.js');
requireApp('system/test/unit/mock_lock_screen.js');
requireApp('system/test/unit/mock_orientation_manager.js');
requireApp('system/test/unit/mock_applications.js');
requireApp('system/test/unit/mock_keyboard_manager.js');
requireApp('system/test/unit/mock_software_button_manager.js');
requireApp('system/test/unit/mock_attention_screen.js');
requireApp('system/test/unit/mock_statusbar.js');
requireApp('system/test/unit/mock_app_window.js');
requireApp('system/test/unit/mock_homescreen_window.js');
requireApp('system/js/system.js');
requireApp('system/js/window_manager.js');
requireApp('system/js/shrinkingui.js');

var mocksForWindowManager = new MocksHelper([
  'LockScreen', 'OrientationManager', 'AttentionScreen',
  'Applications',
  'ManifestHelper', 'KeyboardManager', 'StatusBar', 'SoftwareButtonManager',
  'HomescreenWindow', 'AppWindow'
]).init();

suite('system/ShrinkingUI', function() {
  mocksForWindowManager.attachTestHelpers();
  var clock, stubById;
  var app1, app2, app3, app4, app5, app6, home;
  setup(function(done) {
    clock = this.sinon.useFakeTimers();
    stubById = this.sinon.stub(document, 'getElementById');
    stubById.returns(document.createElement('div'));

    home = new HomescreenWindow('fakeHome');

    app1 = new AppWindow(fakeAppConfig1);
    app2 = new AppWindow(fakeAppConfig2);
    app3 = new AppWindow(fakeAppConfig3);
    app4 = new AppWindow(fakeAppConfig4Background);
    app5 = new AppWindow(fakeAppConfig5Background);
    app6 = new AppWindow(fakeAppConfig6Browser);

    requireApp('system/js/app_window_manager.js', done);
  });

  teardown(function() {
    clock.restore();
    stubById.restore();
  });

  var fakeFTUConfig = {
    url: 'app://www.fakef/index.html',
    manifest: {},
    manifestURL: 'app://www.fakef/ManifestURL',
    origin: 'app://www.fakef'
  };

  var fakeAppConfig1 = {
    url: 'app://www.fake/index.html',
    manifest: {},
    manifestURL: 'app://wwww.fake/ManifestURL',
    origin: 'app://www.fake'
  };

  var fakeAppConfig2 = {
    url: 'app://www.fake2/index.html',
    manifest: {},
    manifestURL: 'app://wwww.fake2/ManifestURL',
    origin: 'app://www.fake2'
  };

  var fakeAppConfig3 = {
    url: 'app://www.fake3/index.html',
    manifest: {},
    manifestURL: 'app://wwww.fake3/ManifestURL',
    origin: 'app://www.fake3'
  };

  var fakeAppConfig4Background = {
    url: 'app://www.fake4/index.html',
    manifest: {},
    manifestURL: 'app://wwww.fake4/ManifestURL',
    origin: 'app://www.fake4',
    stayBackground: true
  };

  var fakeAppConfig5Background = {
    url: 'app://www.fake5/index.html',
    manifest: {},
    manifestURL: 'app://wwww.fake5/ManifestURL',
    origin: 'app://www.fake5',
    stayBackground: true,
    changeURL: true
  };

  var fakeAppConfig6Browser = {
    url: 'app://www.fake6/index.html',
    manifest: {},
    manifestURL: 'app://wwww.fake6/ManifestURL',
    origin: 'app://www.fake6',
    stayBackground: true,
    changeURL: true
  };

  function injectRunningApps() {
    WindowManager.runningApps = {};
    Array.slice(arguments).forEach(function iterator(app) {
      WindowManager.runningApps[app.origin] = app;
    });
  };

  suite('Launch()', function() {
    test('Launch system app', function() {
      var stubDisplay = this.sinon.stub(WindowManager, 'display');
      WindowManager.launch({ url: window.location.href });
      assert.isFalse(stubDisplay.called);
    });

    test('Launch app1 and ShrinkingUI should monitor that', function(done) {
      var stubSwitchTo = this.sinon.stub(ShrinkingUI, '_switchTo');
      WindowManager.runningApps = {};
      WindowManager.launch(fakeAppConfig1);
      assert.isTrue(stubSwitchTo.called);
    });

    /*
    test('Launch app1 and do shrinking', function(done) {
      var stubDisplay = this.sinon.stub(, 'display');
      AppWindowManager.runningApps = {};
      AppWindowManager.launch(fakeAppConfig1);
      assert.isTrue(stubDisplay.called);
      window.dispatchEvent(new CustomEvent('shrinking-start'));
      function callbakc() {

        done();
      }
      ShrinkingUI.state.currentURL;


      // assert.equal(AppWindowManager.displayedApp, app1.origin);
      // assert.deepEqual(AppWindowManager._activeApp, app1);
    });
    */
  });
  /*
  suite('Handle events', function() {
    test('Home Gesture enabled', function() {
      var stubBroadcastMessage =
        this.sinon.stub(AppWindowManager, 'broadcastMessage');
      AppWindowManager.handleEvent({ type: 'homegesture-enabled' });
      assert.isTrue(stubBroadcastMessage.calledWith('homegesture-enabled'));
      stubBroadcastMessage.restore();
    });

    test('Home Gesture disabled', function() {
      var stubBroadcastMessage =
        this.sinon.stub(AppWindowManager, 'broadcastMessage');
      AppWindowManager.handleEvent({ type: 'homegesture-disabled' });
      assert.isTrue(stubBroadcastMessage.calledWith('homegesture-disabled'));
      stubBroadcastMessage.restore();
    });

    test('Press home on home displayed', function() {
      AppWindowManager.runningApps[MockHomescreenLauncher.origin] = home;
      var stubEnsure = this.sinon.stub(home, 'ensure');
      AppWindowManager._activeApp = MockHomescreenLauncher.mHomescreenWindow;
      AppWindowManager.displayedApp = MockHomescreenLauncher.origin;
      AppWindowManager.handleEvent({ type: 'home' });
      assert.isTrue(stubEnsure.called);
      stubEnsure.restore();
    });

    test('Press home on home not displayed', function() {
      AppWindowManager.runningApps[MockHomescreenLauncher.origin] = home;
      AppWindowManager.runningApps[app1.origin] = home;
      var stubDisplay = this.sinon.stub(AppWindowManager, 'display');
      AppWindowManager._activeApp = app1;
      AppWindowManager.displayedApp = app1.origin;
      AppWindowManager.handleEvent({ type: 'home' });
      assert.isTrue(stubDisplay.called);
      stubDisplay.restore();
    });

    test('app is killed at background', function() {
      AppWindowManager.runningApps = {};
      AppWindowManager.displayedApp = app1.origin;
      AppWindowManager._activeApp = app2;
      AppWindowManager.runningApps[app1.origin] = app1;
      AppWindowManager.runningApps[app2.origin] = app2;

      AppWindowManager.handleEvent({ type: 'appterminated', detail: app2 });
      assert.isFalse(app2.origin in AppWindowManager.runningApps);
    });

    test('app is killed at foreground', function() {
      AppWindowManager.runningApps = {};
      AppWindowManager.displayedApp = app1.origin;
      AppWindowManager._activeApp = app1;
      AppWindowManager.runningApps[app1.origin] = app1;
      AppWindowManager.runningApps[app2.origin] = app2;

      AppWindowManager.handleEvent({ type: 'appterminated', detail: app1 });
      assert.isFalse(app1.origin in AppWindowManager.runningApps);
    });

    test('new app instance is created', function() {
      AppWindowManager.runningApps = {};

      AppWindowManager.handleEvent({ type: 'appcreated', detail: app1 });
      assert.isTrue(app1.origin in AppWindowManager.runningApps);
    });

    test('FTU is skipped', function() {
      AppWindowManager.runningApps = {};
      var stubDisplay = this.sinon.stub(AppWindowManager, 'display');

      AppWindowManager.handleEvent({ type: 'ftuskip' });
      assert.isTrue(stubDisplay.calledWith());
    });

    test('System resize', function() {
      AppWindowManager._activeApp = app1;
      var stubResize = this.sinon.stub(app1, 'resize');

      AppWindowManager.handleEvent({ type: 'system-resize' });
      assert.isTrue(stubResize.called);
    });

    test('app request to close', function() {
      AppWindowManager.runningApps = {};
      AppWindowManager.runningApps[app1.origin] = app1;
      var stubIsActive = this.sinon.stub(app1, 'isActive');
      stubIsActive.returns(true);
      var stubDisplay = this.sinon.stub(AppWindowManager, 'display');

      AppWindowManager.handleEvent({ type: 'apprequestclose', detail: app1 });
      assert.isTrue(stubDisplay.calledWith());
    });

    test('app request to open', function() {
      AppWindowManager.runningApps = {};
      AppWindowManager.runningApps[app1.origin] = app1;

      var stubDisplay = this.sinon.stub(AppWindowManager, 'display');

      AppWindowManager.handleEvent({ type: 'apprequestopen', detail: app1 });
      assert.isTrue(stubDisplay.calledWith(app1.origin));
    });

    test('homescreen is created', function() {
      AppWindowManager.runningApps = {};

      AppWindowManager.handleEvent({ type: 'homescreencreated', detail: app1 });
      assert.isTrue(MockHomescreenLauncher.origin in
        AppWindowManager.runningApps);
    });

    test('homescreen is changed', function() {
      var stubDisplay = this.sinon.stub(AppWindowManager, 'display');

      AppWindowManager.handleEvent(
        { type: 'homescreen-changed', detail: app1 });
      assert.isTrue(stubDisplay.calledWith());
    });

    test('kill app', function() {
      var stubKill = this.sinon.stub(AppWindowManager, 'kill');

      AppWindowManager.handleEvent({ type: 'killapp', detail: app1 });
      assert.isTrue(stubKill.called);
    });

    test('app uninstalled', function() {
      var stubKill = this.sinon.stub(AppWindowManager, 'kill');

      AppWindowManager.handleEvent({ type: 'applicationuninstall',
        detail: {
          application: app1
        }
      });
      assert.isTrue(stubKill.called);
    });

    test('display app', function() {
      AppWindowManager.runningApps = {};
      AppWindowManager.runningApps[app1.origin] = app1;

      var stubDisplay = this.sinon.stub(AppWindowManager, 'display');

      AppWindowManager.handleEvent({ type: 'displayapp', detail: app1 });
      assert.isTrue(stubDisplay.calledWith(app1.origin));

    });

    test('Hide whole windows', function() {
      var stubSetAttribute =
        this.sinon.stub(AppWindowManager.element, 'setAttribute');

      AppWindowManager.handleEvent({ type: 'hidewindows' });
      assert.isTrue(stubSetAttribute.calledWith('aria-hidden', 'true'));
    });

    test('Show whole windows', function() {
      var stubSetAttribute =
        this.sinon.stub(AppWindowManager.element, 'setAttribute');

      AppWindowManager.handleEvent({ type: 'showwindows' });
      assert.isTrue(stubSetAttribute.calledWith('aria-hidden', 'false'));
    });

    test('Launch app', function() {
      var stubLaunch =
        this.sinon.stub(AppWindowManager, 'launch');

      AppWindowManager.handleEvent(
        { type: 'launchapp', detail: fakeAppConfig1 });
      assert.isTrue(stubLaunch.calledWith(fakeAppConfig1));
    });

    test('Show top window', function() {
      AppWindowManager.runningApps = {};
      AppWindowManager.runningApps[app1.origin] = app1;
      AppWindowManager._activeApp = app1;
      MockAttentionScreen.mFullyVisible = false;
      var stubSetVisible = this.sinon.stub(app1, 'setVisible');

      AppWindowManager.handleEvent({
        type: 'showwindow'
      });

      assert.isTrue(stubSetVisible.calledWith(true));
    });

    test('Hide top window', function() {
      AppWindowManager.runningApps = {};
      AppWindowManager.runningApps[app1.origin] = app1;
      AppWindowManager._activeApp = app1;
      var stubSetVisible = this.sinon.stub(app1, 'setVisible');

      AppWindowManager.handleEvent({
        type: 'hidewindow'
      });

      assert.isTrue(stubSetVisible.calledWith(false));
    });

    test('Overlay start on top of in process app', function() {
      AppWindowManager.runningApps = {};
      AppWindowManager.runningApps[app6.origin] = app6;
      AppWindowManager._activeApp = app6;
      AppWindowManager.displayedApp = app6.origin;
      var stubIsOOP = this.sinon.stub(app6, 'isOOP');
      stubIsOOP.returns(false);
      var stubSetVisible = this.sinon.stub(app6, 'setVisible');

      AppWindowManager.handleEvent({ type: 'overlaystart' });
      assert.isTrue(stubSetVisible.calledWith(false));
    });

    test('Overlay start on top of OOP app', function() {
      AppWindowManager.runningApps = {};
      AppWindowManager.runningApps[app1.origin] = app1;
      AppWindowManager._activeApp = app1;
      AppWindowManager.displayedApp = app1.origin;
      var stubBlur = this.sinon.stub(app1, 'blur');

      AppWindowManager.handleEvent({ type: 'overlaystart' });
      assert.isTrue(stubBlur.called);
    });
  });

  suite('Kill()', function() {
    test('kill()', function() {
      AppWindowManager.runningApps = {};
      AppWindowManager.runningApps[app1.origin] = app1;
      var stubKill = this.sinon.stub(app1, 'kill');

      AppWindowManager.kill(app1.origin);
      assert.isTrue(stubKill.called);
    });
  });

  suite('updateActiveApp()', function() {
    test('', function() {
      injectRunningApps(app1, app2, app3, app4);
      AppWindowManager._activeApp = null;
      AppWindowManager.displayedApp = '';
      AppWindowManager._updateActiveApp(app1.origin);
      assert.equal(AppWindowManager.displayedApp, app1.origin);
      assert.deepEqual(AppWindowManager._activeApp, app1);
    });
  });
  */

});
