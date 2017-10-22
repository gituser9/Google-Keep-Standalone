import Cocoa
import WebKit


class ViewController: NSViewController, WebFrameLoadDelegate, WebPolicyDelegate {

    @IBOutlet weak var webView: WebView!
    @IBOutlet weak var splashImage: NSImageView!
    @IBOutlet weak var waitIndicator: NSProgressIndicator!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        let url = URL(string: "https://keep.google.com")!

        waitIndicator.startAnimation(nil)
        webView.isHidden = true
        webView.mainFrame?.load(URLRequest(url: url))
        webView.frameLoadDelegate = self
        webView.policyDelegate = self
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
    
    func webView(_ webView: WebView!, decidePolicyForNewWindowAction actionInformation: [AnyHashable : Any]!, request: URLRequest!, newFrameName frameName: String!, decisionListener listener: WebPolicyDecisionListener!) {
        guard let currentUrl = request.url else {
            return
        }
        listener.ignore()
        NSWorkspace.shared().open(currentUrl)
    }
}





































