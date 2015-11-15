/**
  *@file objectrenderer.h
  *@author Durgesh and Atul Shree
  *@date 7 Sep 2013
  */
#include"objectRender.h"
#include<stdio.h>
#include<string.h>
#include"libtarga.h"
#include"texture.h"
/**
 * @brief Object::Object constructor which initialises the boolean isDisplayListCreated to false
 */
Object::Object(){
    this->isDisplayListCreated = false ;
}
/**
 * @brief Object::~Object delets the GLModel object model which is used to access vertices of the polygons and triangles
 */
Object::~Object(){
    delete this->model;
}
/**
 * @brief Object::readObj reads the .obj file into the variable model and reads Texture filename width heigth into
 * data w and h variables respectively
 * @param filename
 */
void Object::readObj(char *filename){
    this->model = glmReadOBJ(filename) ;
    int w=0, h=0 ;
    char *data ;
    data = (char*)tga_load(model->texture_file, &w, &h, TGA_TRUECOLOR_24);

    Texture texture ;
    texture.loadTexture(data, w, h, this->textureID) ;
}

/**
 * @brief Object::drawObj Draws all the Triangles and Polygons read into model variable with specified texture co-ordinates
 */
void Object::drawObj(){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, this->textureID);
    if(!this->isDisplayListCreated){ // create display list if not created
        this->isDisplayListCreated = true;
        this->displayListID = glGenLists(1) ;
        glNewList(this->displayListID, GL_COMPILE);
    // draw all triangles
    GLMtriangle *triangles=model->triangles;
    for(int i=0; i<model->numtriangles; i++){
        glBegin(GL_TRIANGLES);
        glTexCoord2f(model->texcoords[2*(*(triangles+i)).tindices[0]], model->texcoords[2*(*(triangles+i)).tindices[0]+1]);
        glVertex3f( model->vertices[3*(*(triangles+i)).vindices[0]], model->vertices[3*(*(triangles+i)).vindices[0]+1],
                    model->vertices[3*(*(triangles+i)).vindices[0]]+2);
        glTexCoord2f(model->texcoords[2*(*(triangles+i)).tindices[1]], model->texcoords[2*(*(triangles+i)).tindices[1]+1]);
        glVertex3f( model->vertices[3*(*(triangles+i)).vindices[1]], model->vertices[3*(*(triangles+i)).vindices[1]+1],
                    model->vertices[3*(*(triangles+i)).vindices[1]]+2);
        glTexCoord2f(model->texcoords[2*(*(triangles+i)).tindices[2]], model->texcoords[2*(*(triangles+i)).tindices[2]+1]);
        glVertex3f( model->vertices[3*(*(triangles+i)).vindices[2]], model->vertices[3*(*(triangles+i)).vindices[2]+1],
                    model->vertices[3*(*(triangles+i)).vindices[2]]+2);
        glEnd();
    }

    // draw all polygons
    GLMpolygon *polygon=model->polygons;
    for(int i=0; i<model->numpolygons; i++){
        glBegin(GL_POLYGON);
        for(int j=0; j< (*(polygon+i)).numvertices; j++){
            if((*(polygon+i)).t==1) glTexCoord2f(model->texcoords[2*(*(polygon+i)).tindices[j]],
                                                model->texcoords[2*(*(polygon+i)).tindices[j]+1]);

            glVertex3f(model->vertices[3*(*(polygon+i)).vindices[j]], model->vertices[3*(*(polygon+i)).vindices[j]+1],
                       model->vertices[3*(*(polygon+i)).vindices[j]+2]);
        }
        glEnd();
    }
    glEndList() ;
    }


    glCallList(this->displayListID);
    glFlush();
}
