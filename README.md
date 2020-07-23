# TR_GRAFKOM_I_9
GLfloat lightIntensity[] = {0.7f,0.7f,0.7f,1.0f};//mensetting pencahayaan
GLfloat light_position[] = {2.0f,6.0f,3.0f,0.0f};
glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
glLightfv(GL_LIGHT0,GL_POSITION,light_position);
