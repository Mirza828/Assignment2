
#include <iostream>
#include <stack>
#include <string>
using namespace std;

struct WebPage {
    string url;        
    string title;      

    WebPage(string u, string t) : url(u), title(t) {}
};


class BrowsingHistory {
private:
    stack<WebPage> historyStack;  

public:
    
    void addVisitedURL(const string& url, const string& title) {
        WebPage newPage(url, title);
        historyStack.push(newPage);
        cout << "Added URL: " << url << " - " << title << endl;
    }


    void clearHistory() {
        while (!historyStack.empty()) {
            historyStack.pop();
        }
        cout << "Browsing history cleared." << endl;
    }

    
    void displayHistory() {
        if (historyStack.empty()) {
            cout << "No browsing history available." << endl;
            return;
        }

        stack<WebPage> tempStack = historyStack;  
        cout << "Browsing History (most recent to oldest):" << endl;
        while (!tempStack.empty()) {
            WebPage currentPage = tempStack.top();
            cout << "Title: " << currentPage.title << ", URL: " << currentPage.url << endl;
            tempStack.pop();
        }
    }
};

int main() {
    BrowsingHistory history;

    
    history.addVisitedURL("https://www.google.com", "Google");
    history.addVisitedURL("https://www.youtube.com", "YouTube");
    history.addVisitedURL("https://www.github.com", "GitHub");

    
    history.displayHistory();
    history.clearHistory();
    history.displayHistory();

    return 0;
}
