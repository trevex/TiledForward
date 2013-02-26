#ifndef _APP_H_
#define _APP_H_

#include <string>

#define App CApp::instance()

class CApp {
public:
	CApp(void);
	~CApp(void);

	static CApp& instance(void);

	bool initialize(std::string title, int width = 800, int height = 600, bool fullscreen = false);
	bool isRunning(void) const;
	bool run(void);
protected:
private:
	bool m_bRunning;
};

#endif