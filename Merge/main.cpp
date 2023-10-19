// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

// FCI – Programming 1 – 2023 - Assignment 1
// Program Name: xxxxxx.cpp
// Author1 and ID and email: Ali sidatt - 20210762 - 11410120210762@stud.cu.edu.eg
// Author2 and ID and email: Nada Abu Bakr Suleiman - 20220715 - Nadaabobaker11@gmail.com
// Author3 and ID and email: Aya Sayid Muhammad - 20220077
// Purpose: A program to add filters to images size 256x256 type bitmap using a ready-made library (bmplib).


#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"


using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];
unsigned char image4[SIZE][SIZE];
unsigned char coloredImage[SIZE][SIZE][RGB];
unsigned char coloredImage2[SIZE][SIZE][RGB];
unsigned char coloredImage3[SIZE][SIZE][RGB];
unsigned char coloredImage4[SIZE][SIZE][RGB];



void loadImage ();
void loadImage2();
void saveImage ();
void mergeImages();
void Brightness();
void shrinkImage();
void rotateImage();
void cropImage();
void loadColoerdImage ();
void loadColoerdImage2();
void saveColoredImage ();
void mergeColoredImages();
void coloredImageBrightness();
void shrinkColoredImages();
void rotateColoredImage();
void cropColoredImage();

int main()
{
    int a;
    cout<<"Chose image type... \n\n1- Grey scale\n\n2- Full colored\n\n";
    cin>>a;
    switch (a)
    {
    case 1:
    {
        int x;
        cout<<"\nChose filter... \n\n1- Merge images\n\n2- Brightness\n\n3- Shrink image\n\n4- Rotate image\n\n5- Crop image\n\n";
        cin>>x;
        switch (x)
        {
            case 1:
            {
                loadImage();
                loadImage2();
                mergeImages();
                saveImage();
                break;
            }
             case 2:
            {
                loadImage();
                Brightness();
                saveImage();
                break;
            }
            case 3:
            {
                loadImage();
                shrinkImage();
                saveImage();
                break;
            }
            case 4:
            {
                loadImage();
                rotateImage();
                saveImage();
                break;
            }
            case 5:
            {
                loadImage();
                cropImage();
                saveImage();
                break;
            }
        }
        break;
    }
    case 2:
    {
        int x;
        cout<<"\nChose filter... \n\n1- Merge images\n\n2- Brightness\n\n3- Shrink image\n\n-4 Rotate image\n\n5- Crop image\n\n";
        cin>>x;
        switch (x)
        {
        case 1:
        {
            loadColoerdImage();
            loadColoerdImage2();
            mergeColoredImages();
            saveColoredImage();
            break;
        }

        case 2:
        {
            loadColoerdImage();
            coloredImageBrightness();
            saveColoredImage();
            break;
        }
        case 3:
        {
            loadColoerdImage();
            shrinkColoredImages();
            saveColoredImage();
            break;
        }
        case 4:
        {
            loadColoerdImage();
            rotateColoredImage();
            saveColoredImage();
            break;
        }
        case 5:
            {
                loadColoerdImage();
                cropColoredImage();
                saveColoredImage();
                break;
            }
        }
    }
}


    return 0;
}
//_________________________________________
void loadImage ()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "\nEnter the source image file name: \n\n";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}


void loadImage2 ()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "\nEnter the second image file name: \n\n";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image2);
}

//_________________________________________
void saveImage ()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "\nEnter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image4);
}

//_________________________________________
void mergeImages()
{
    for (int i = 0; i <SIZE; i++)
    {

        for (int j = 0; j< SIZE; j++)
        {
            image4 [i] [j] = (image [i] [j] + image2[i][j])/2;
        }
    }
}
void Brightness()
{
    int a;
    cout<<"\n\n1- increase brightness\n\n2- Decrease brightness\n\n";
    cin>>a;
    switch (a)
    {
    case 1:
    {
        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE; j++)
            {
                image2[i][j] =image[0][0] ;
            }
        }
        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE; j++)
            {
                image4[i][j] =(image[i][j]+image2[i][j])/2 ;
            }
        }
        break;
    }
    case 2:
    {
        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE; j++)
            {
                image4[i][j] =image[i][j]/2 ;
            }
        }
        break;
    }
    }

}

void loadColoerdImage()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "\nEnter the source image file name: \n\n";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, coloredImage);
}

void loadColoerdImage2()
{
    char imageFileName[100];

    // Get gray scale image file name
    cout << "\nEnter the source image file name: \n\n";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, coloredImage2);
}

void saveColoredImage()
{
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "\nEnter the target image file name: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeRGBBMP(imageFileName, coloredImage4);
}

void mergeColoredImages()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j< SIZE; j++)
        {
            for (int k = 0; k< RGB; k++)
            {
                coloredImage4[i][j][k] = (coloredImage[i][j][k] + coloredImage2[i][j][k])/2;
            }
        }
    }
}

void coloredImageBrightness()
{
    int a;
    cout<<"\n\n1- Increase brightness\n\n2- Decrease brightness\n\n";
    cin>>a;
    switch (a)
    {
    case 1:
    {
        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    coloredImage2[i][j][k] =coloredImage[0][0][0] ;
                }
            }
        }
        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    coloredImage4[i][j][k] =(coloredImage[i][j][k]+coloredImage2[i][j][k])/2 ;
                }
            }
        }
        break;
    }
    case 2:
    {
        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE; j++)
            {
                for(int k=0; k<SIZE; k++)
                {
                    coloredImage4[i][j][k] =(coloredImage[i][j][k])/2 ;
                }
            }
        }
        break;
    }
    }

}

void shrinkImage()
{
    int x;
    cout<<"\n\n1- Shrink 1/2\n\n2- Shrink 1/3\n\n3- Shrink 1/4\n\n";
    cin>>x;
    switch (x)
    {
    case 1:
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image4 [i/2] [j/2] = image [i] [j];
            }
        }
        break;
    }

    case 2:
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image4 [i/3] [j/3] = image [i] [j];
            }
        }
        break;
    }
    case 3:
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image4 [i/4] [j/4] = image [i] [j];
            }
        }
        break;
    }
    }

}

void shrinkColoredImages()
{
    int x;
    cout<<"\n\n1- Shrink 1/2\n\n2- Shrink 1/3\n\n3- Shrink 1/4\n\n";
    cin>>x;
    switch (x)
    {
    case 1:
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k = 0; k< RGB; k++)
                {
                    coloredImage4 [i/2] [j/2] [k]= coloredImage [i] [j][k];
                }
            }
        }
        break;
    }

    case 2:
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k = 0; k< RGB; k++)
                {
                    coloredImage4 [i/3] [j/3] [k]= coloredImage [i] [j][k];
                }
            }
        }
        break;
    }
    case 3:
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k = 0; k< RGB; k++)
                {
                    coloredImage4 [i/4] [j/4] [k]= coloredImage [i] [j][k];
                }
            }
        }
        break;
    }
    }

}


void rotateImage()
{

    int c;
    cout<<"1- To rotate 90 click ==> 1\n2- To rotate 180 click ==> 2\n3- To rotate 270 click ==> 3\n";
    cin>>c;
    switch(c)
    {
    case 1:
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image3 [i] [j] = image[256-j][256-i];
                image4 [i] [j] = image3[i][j];
            }

        }
        break;
    }

    case 2:
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image3 [i] [j] = image[256-j][256-i];
            }

        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image4 [i] [j] = image3[j][i];
            }

        }
        break;
    }

    case 3:
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image3 [i] [j] = image[256-j][256-i];
            }

        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image2 [i] [j] = image3[j][i];
            }

        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                image3 [i] [j] = image2[256-j][256-i];
                image4 [i] [j] = image3 [i] [j];
            }

        }
        break;
    }
    }
}

void cropImage()
{
    int x,y;
    cout<<"\n\nEnter X, Y position...??\nX ==>  ";
    cin>>x;
    cout<<"\nY ==>  ";
    cin>>y;
    if(x>=0 && x<=SIZE && y>=0 && y<=SIZE)
    {
        int sqrLength;
        cout<<"\n\nEnter the square length...\n";
        cin>>sqrLength;
        for (int i = 0; i <SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                if(i>=x && i <= sqrLength+x && j>=y && j<= sqrLength+y)
                {
                    image4 [i] [j] = image [i] [j] ;
                }
                else
                    image4 [i] [j] = image [256] [256] ;
            }
        }
    }


}

void cropColoredImage()
{
    int x,y;
    cout<<"\n\nEnter X, Y position...??\nX ==>  ";
    cin>>x;
    cout<<"\nY ==>  ";
    cin>>y;
    if(x>=0 && x<=SIZE && y>=0 && y<=SIZE)
    {
        int sqrLength;
        cout<<"\n\nEnter the square length...\n";
        cin>>sqrLength;
        for (int i = 0; i <SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    if(i>=x && i <= sqrLength+x && j>=y && j<= sqrLength+y)
                    {
                        coloredImage4 [i] [j] [k]= coloredImage [i] [j][k] ;
                    }
                    else
                        coloredImage4 [i] [j][k] = coloredImage [256] [256][k] ;
                }
            }
        }
    }
}

void rotateColoredImage()
{

    int c;
    cout<<"1- To rotate 90 click ==> 1\n2- To rotate 180 click ==> 2\n3- To rotate 270 click ==> 3\n";
    cin>>c;
    switch(c)
    {
    case 1:
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for (int k = 0; k< RGB; k++)
                {
                    coloredImage3 [i] [j] [k]= coloredImage[256-j][256-i][k];
                    coloredImage4 [i] [j] [k]= coloredImage3[i][j][k];
                }
            }

        }
        break;
    }

    case 2:
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    coloredImage3 [i] [j][k] = coloredImage[256-j][256-i][k];
                }
            }

        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    coloredImage4 [i] [j][k] = coloredImage3[j][i][k];
                }
            }

        }
        break;
    }

    case 3:
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    coloredImage3 [i] [j][k] = coloredImage[256-j][256-i][k];
                }
            }

        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    coloredImage2 [i] [j][k] = coloredImage3[j][i][k];
                }
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j< SIZE; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    coloredImage3 [i] [j][k] = coloredImage2[256-j][256-i][k];
                    coloredImage4 [i] [j][k] = coloredImage3 [i] [j][k];
                }
            }
        }
        break;
    }
    }
}


