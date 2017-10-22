import Cocoa


@NSApplicationMain
class AppDelegate: NSObject, NSApplicationDelegate {

    let statusItem = NSStatusBar.system().statusItem(withLength: 20)


    func applicationDidFinishLaunching(_ aNotification: Notification) {        
        if let button = statusItem.button {
            let trayImage = NSImage(named: "google-keep-tray")
            button.image = trayImage
            button.action = #selector(showHide(_:))
        }
    }

    func applicationWillTerminate(_ aNotification: Notification) {
        // Insert code here to tear down your application
    }


    
    @objc func showHide(_ sender: Any?) {
        if let window = NSApplication.shared().windows.last {
            if window.isVisible {
                NSApplication.shared().windows.last?.orderOut(self)
            } else {
                window.makeKeyAndOrderFront(self)
                NSApp.activate(ignoringOtherApps: true)
            }
        }
    }
}

