#ifndef _RENDERER_H_
#define _RENDERER_H_

#define Renderer CRenderer::instance()

class CRenderer {
public:
	CRenderer(void);
	~CRenderer(void);

	static CRenderer& instance(void);

	bool initialize(void);
	void resize(float width, float height);
	void render(void);
protected:
private:
};

#endif