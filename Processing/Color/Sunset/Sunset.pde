int x = 0;
int y = 0;
int space = 1;
int r = 1;
double count = (501 / space) * (501 / space);
float[] c1 = {63, 127, 255};
double[] c2 = {255, 139, 233};
double change0 = (c2[0] - c1[0]) / count;
double change1 = (c2[1] - c1[1]) / count;
double change2 = (c2[2] - c1[2]) / count;
void setup() {
  size(500, 500);
  print(count);
  
}

void draw() {
  //background(200);
  fill(c1[0],c1[1],c1[2]);
  stroke(c1[0],c1[1],c1[2]);
  c1[0] += change0;
  c1[1] += change1;
  c1[2] += change2;
  circle(x,y,r);
  x += space;
  if (x > 500) {
    if (y > 500) {
      save("blue_pink.png");
      noLoop();
    }
    y += space;
    x = 0;
  }
}
