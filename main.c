#include <GL/glut.h>
#include <stdlib.h>

#define WIDTH 320
#define HEIGHT 240

// 回転角度(度)
static float angle = 0.0f;

// 赤
static const GLfloat red[] = {1.0f, 0.0f, 0.0f, 1.0f};

// ライトの位置と色
static const GLfloat lightpos[] = {100.0f, 150.0f, -100.0f, 1.0f};
static const GLfloat ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};
static const GLfloat diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};

void display(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // 視点の設定
  gluLookAt(150.0, 100.0, -200.0, // カメラの座標
            0.0, 0.0, 0.0,        // 注視点の座標
            0.0, 1.0, 0.0);       // 画面の上方向を指すベクトル

  // ライトの設定(視点変換の後に指定すると世界座標で固定される)
  glLightfv(GL_LIGHT0, GL_POSITION, lightpos);

  // マテリアルの設定と立方体の描画
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
  glRotatef(angle, 0.0f, 1.0f, 0.0f);
  glutSolidCube(40.0);

  glutSwapBuffers();
}

void reshape(int w, int h) {
  if (h == 0) {
    h = 1;
  }
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  // 視野角,アスペクト比(ウィンドウの幅/高さ),描画する範囲(最も近い距離,最も遠い距離)
  gluPerspective(30.0, (double)w / (double)h, 1.0, 1000.0);
}

// 約60fpsで回転させる
void timer(int value) {
  (void)value;
  angle += 1.0f;
  if (angle >= 360.0f) {
    angle -= 360.0f;
  }
  glutPostRedisplay();
  glutTimerFunc(16, timer, 0);
}

// ESC または q で終了
void keyboard(unsigned char key, int x, int y) {
  (void)x;
  (void)y;
  if (key == 27 || key == 'q') {
    exit(0);
  }
}

void Init(void) {
  glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow("Cube");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutTimerFunc(0, timer, 0);
  Init();
  glutMainLoop();
  return 0;
}
