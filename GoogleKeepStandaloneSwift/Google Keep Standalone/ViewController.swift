//
//  ViewController.swift
//  Google Keep Standalone
//
//  Created by user on 09.10.17.
//  Copyright © 2017 user. All rights reserved.
//

import Cocoa
import WebKit

class ViewController: NSViewController, WebFrameLoadDelegate {

    @IBOutlet weak var webView: WebView!
    @IBOutlet weak var splashImage: NSImageView!
    @IBOutlet weak var waitIndicator: NSProgressIndicator!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let url = URL(string: "https://keep.google.com")!

        waitIndicator.startAnimation(nil)
        webView.isHidden = true
        webView.mainFrame?.load(URLRequest(url: url))
        
        self.webView.frameLoadDelegate = self
    }

    override var representedObject: Any? {
        didSet {
        // Update the view, if already loaded.
        }
    }
    
    func webView(_ sender: WebView!, didFinishLoadFor frame: WebFrame!) {
        waitIndicator.stopAnimation(nil)
        splashImage.isHidden = true
        webView.isHidden = false
    }

}

