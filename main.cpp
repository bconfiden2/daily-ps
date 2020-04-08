#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
    GLFWwindow* window;

    if(!glfwInit())  // 시작시키기
    {
        return -1;
    }

    window = glfwCreateWindow(800, 800, "KIM SANG HONG", NULL, NULL);  // 윈도우 크기, 이름

    if(!window)
    {
        glfwTerminate();  // 종료시키기
        return -1;
    }

    glfwMakeContextCurrent(window);  //앞으로 먹을 opengl 명령어는 해당 윈도우에서 작동할 것
    
    if(glewInit() != GLEW_OK)
    {
        std::cout << "GLEW Init Error!" << std::endl;
        return -1;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;
    while(!glfwWindowShouldClose(window))
    {
        // Render here
        glClearColor(1.0, 1.0, 1.0, 1.0);  // 화면을 무슨 색깔로 지울 것인지
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // 해당 컬러를 이용해 컬러버퍼를 지운다

        glfwSwapBuffers(window);  // 두개 버퍼를 바꿔준다(부드러운 애니메이션)

        glfwPollEvents();  // 이벤트들을 처리해주는 기능
    }

    glfwTerminate();
    return 0;
}