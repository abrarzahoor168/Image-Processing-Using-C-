    
    #include <iostream>
#include <stdlib.h>
#include <string.h>
#include <conio.h>   ///to use _getche
#include <Windows.h> ///to  use  gotoxy and  setcolor
#include<stdio.h>
#define THRESHOLD 128
#define BLACK 0
#define WHITE 255
#define MAX_VALUE 255

using namespace std;

void gotoxy(short int, short int);
void setColor(int);

void gotoxy(short int x, short int y)
{
    COORD cur = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

bool loading()
{
    char ch;
    gotoxy(20, 23); /// Loading
    setColor(8);
    cout << "Loading...  ";
    gotoxy(5, 24);
    for (int i = 5; i <= 105; i++)
    {
        cout << "|";
        Sleep(15);
        gotoxy(37, 23);
        cout << i - 5 << " %";
        Sleep(15);
        gotoxy(i, 24);
    }
    setColor(12);
    gotoxy(30, 26);
    cout << "Press any key to continue ....";
    gotoxy(30, 27);
    cout<<"Press Esc to exit...";
    ch = _getch();
    if (ch == 27)
        return false;
    else
        return true;
}
void improcess()
{
    gotoxy(20, 23); /// Loading
    setColor(8);
    cout << "Applying Filter...  ";
    gotoxy(5, 24);
    for (int i = 5; i <= 105; i++)
    {
        cout << "|";
        Sleep(15);
        gotoxy(37, 23);
        cout << i - 5 << " %";
        Sleep(15);
        gotoxy(i, 24);
    }
    system("cls");
    gotoxy(30, 26);
    cout << "Image is saved in the designated folder ....";
}

void my_exit()
{
	system("cls");
	gotoxy(55, 13);
	setColor(11);
	cout << "Good Bye !!!";
	gotoxy(47, 17);
	_getch();
	exit(1);
}

void setColor(int c)
{ ///if (c < 15&& c> 0) font  color  else  background color
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    SetConsoleTextAttribute(hConsole, (csbi.wAttributes & 0xFFF0) | (WORD)c); /// For ground colors take up the least significant byte
}

void name_and_rol_no()
{
    ///system("color fc");
    gotoxy(30, 15);
    setColor(11);
    cout << "PROJECT BY...";
    gotoxy(30, 18);
    setColor(14);
    char name[] = " ABRAR ZAHOOR AND AMAAN BILAL ";
    for (int i = 0; name[i] != '\0'; i++)
    {
        Sleep(80);
        cout << name[i];
    }
    setColor(14);
    gotoxy(30, 19);
    char rollno[] = " 2K19/IT/004	2K19/IT/011 ";
    for (int i = 0; rollno[i] != '\0'; i++)
    {
        Sleep(80);
        cout << rollno[i];
    }
}

int main()
{
    name_and_rol_no();
    bool flag =loading();
    char press;
    int n;
    setColor(11);
   hell:system("cls");
    if(flag)
    {
    hell1:system("cls");
    cout<<"\n\nPlease Select the Image filter :"<<endl;
    setColor(11);
    cout <<"\nPress 1 for RGB TO Grey" << endl;
    setColor(11);
    cout<<"\nPress 2 for RGB TO SPEIA"<<endl;
    cout<<"\nPress 3 for BLACK AND WHITE" << endl;
    cout<<"\nPress 4 to Rotate"<<endl;
    cout<<"\nPress 5 for Generating the Negative of the image"<<endl;
    cin>>n;

    switch (n)
    {
    case 1/* constant-expression */:
        /* code */
        {
            FILE *fIn = fopen("airplane.bmp", "rb");
            FILE *fOut = fopen("images/airplane_grey.bmp", "w+");
            int i, j, y;
            unsigned char byte[54];

            if (fIn == NULL) // Base case testing whether or not the input file is present
            {
                cout << ("File does not exist.\n");
        }

        for (i = 0; i < 54; i++) //reading the 54 byte header via the input image from the function fIn
        {
            byte[i] = getc(fIn);
        }

        fwrite(byte, sizeof(unsigned char), 54, fOut); //writing back the header in the processed image

        // extracting image height, width and bitDepth from the input imageHeader
        int height = *(int *)&byte[18];
        int width = *(int *)&byte[22];
        int bitDepth = *(int *)&byte[28];

        cout << "width: \n"
             << width << endl;
        cout << "height: \n"
             << height << endl;

        int size = height * width; //calculating the image size from the given dimensions

        unsigned char buffer[size][3]; //storing the image data extracted from the calculated size

        for (i = 0; i < size; i++) //Converting RGB colours to gray
        {
            y = 0;
            buffer[i][2] = getc(fIn); //blue
            buffer[i][1] = getc(fIn); //green
            buffer[i][0] = getc(fIn); //red

            y = (buffer[i][0] * 0.3) + (buffer[i][1] * 0.59) + (buffer[i][2] * 0.11); //converting the RGB colors by multiplying with the respective values

            putc(y, fOut);
            putc(y, fOut);
            putc(y, fOut);
        }
        cout << endl<< endl;
        improcess();
         fclose(fOut);
         fclose(fIn);
        }
         break;
    case 2:
    {
        FILE *fIn = fopen("airplane.bmp", "rb");        //Input File name
        FILE *fOut = fopen("images/airplane_sepia.bmp", "w+"); //Output File name

        int i, r, g, b;
        unsigned char byte[54];

        if (fIn == NULL) // check if the input file has not been opened succesfully.
        {
            cout<<"File does not exist.\n";
        }

        for (i = 0; i < 54; i++) //read the 54 byte header from fIn
        {
            byte[i] = getc(fIn);
        }

        fwrite(byte, sizeof(unsigned char), 54, fOut); //write the header back

        // extract image height, width and bitDepth from imageHeader
        int height = *(int *)&byte[18];
        int width = *(int *)&byte[22];
        int bitDepth = *(int *)&byte[28];

        cout<<"width: \n"<<width;
        cout<<"height: \n"<< height;

        int size = height * width; //calculate image size

        unsigned char buffer[size][3]; //to store the image data

        for (i = 0; i < size; i++)
        {
            r = 0;
            g = 0;
            b = 0;
            buffer[i][2] = getc(fIn); //blue
            buffer[i][1] = getc(fIn); //green
            buffer[i][0] = getc(fIn); //red

            //conversion formula of rgb to sepia
            r = (buffer[i][0] * 0.393) + (buffer[i][1] * 0.769) + (buffer[i][2] * 0.189);
            g = (buffer[i][0] * 0.349) + (buffer[i][1] * 0.686) + (buffer[i][2] * 0.168);
            b = (buffer[i][0] * 0.272) + (buffer[i][1] * 0.534) + (buffer[i][2] * 0.131);

            if (r > MAX_VALUE)
            { //if value exceeds
                r = MAX_VALUE;
            }
            if (g > MAX_VALUE)
            {
                g = MAX_VALUE;
            }
            if (b > MAX_VALUE)
            {
                b = MAX_VALUE;
            }
            putc(b, fOut);
            putc(g, fOut);
            putc(r, fOut);
        }

        fclose(fOut);
        fclose(fIn);
        cout<<endl<<endl;
        improcess();
    }
        break;
    case 3:{
        FILE *fIn = fopen("barbara.bmp", "rb"); //Input File name
        FILE *fOut = fopen("images/b_w.bmp", "wb");   //Output File name

        int i;
        unsigned char byte[54];         //to get the image header
        unsigned char colorTable[1024]; //to get the colortable

        if (fIn == NULL) // check if the input file has not been opened succesfully.
        {
            cout<<"File does not exist.\n";
        }

        for (i = 0; i < 54; i++) //read the 54 byte header from fIn
        {
            byte[i] = getc(fIn);
        }

        fwrite(byte, sizeof(unsigned char), 54, fOut); //write the header back

        // extract image height, width and bitDepth from imageHeader
        int height = *(int *)&byte[18];
        int width = *(int *)&byte[22];
        int bitDepth = *(int *)&byte[28];

        cout<<"width: \n"<<width;
        cout<<"height: \n"<< height;
        int size = height * width; //calculate image size

        if (bitDepth <= 8) //if ColorTable present, extract it.
        {
            fread(colorTable, sizeof(unsigned char), 1024, fIn);
            fwrite(colorTable, sizeof(unsigned char), 1024, fOut);
        }

        unsigned char buffer[size]; //to store the image data

        fread(buffer, sizeof(unsigned char), size, fIn); //read image data

        for (i = 0; i < size; i++) //store 0(black) and 255(white) values to buffer
        {
            buffer[i] = (buffer[i] > THRESHOLD) ? WHITE : BLACK;
        }

        fwrite(buffer, sizeof(unsigned char), size, fOut); //write back to the output image

        fclose(fIn);
        fclose(fOut);
        cout << endl<< endl;
        improcess();

    }
        break;
    case 4:{
        FILE *fIn = fopen("barbara.bmp", "rb");       //Input File name
        FILE *fOut = fopen("images/barbara_rot.bmp", "wb"); //Output File name

        int i, j, choice;
        unsigned char byte[54], colorTable[1024];

        if (fIn == NULL) // check if the input file has not been opened succesfully.
        {
            cout<<"File does not exist.\n";
        }

        for (i = 0; i < 54; i++) //read the 54 byte header from fIn
        {
            byte[i] = getc(fIn);
        }

        fwrite(byte, sizeof(unsigned char), 54, fOut); //write the header back

        // extract image height, width and bitDepth from imageHeader
        int height = *(int *)&byte[18];
        int width = *(int *)&byte[22];
        int bitDepth = *(int *)&byte[28];

        cout<<"width: \n"<<width;
        cout<<"height: \n"<< height;

        int size = height * width; //calculate image size

        if (bitDepth <= 8) //if ColorTable present, extract it.
        {
            fread(colorTable, sizeof(unsigned char), 1024, fIn);
            fwrite(colorTable, sizeof(unsigned char), 1024, fOut);
        }

        unsigned char buffer[width][height]; //to store the image data
        unsigned char out_buffer[width][height];

        fread(buffer, sizeof(unsigned char), size, fIn); //read the image data

        cout<<"Enter your choice :\n";
        cout<<"1. Rotate left\n";
        cout<<"2. Rotate right\n";
        cout<<"3. Rotate 180\n";

        cin>>choice;

        switch (choice) //to rotate image in 3 direction
        {
        case 1:
            for (i = 0; i < width; i++) //to rotate left
            {
                for (j = 0; j < height; j++)
                {
                    out_buffer[j][height - 1 - i] = buffer[i][j];
                }
            }
            break;
        case 2:
            for (i = 0; i < width; i++) //to rotate right
            {
                for (j = 0; j < height; j++)
                {
                    out_buffer[j][i] = buffer[i][j];
                }
            }
            break;
        case 3:
            for (i = 0; i < width; i++) //to rotate 180 degree
            {
                for (j = 0; j < height; j++)
                {
                    out_buffer[width - i][j] = buffer[i][j];
                }
            }
            break;
        default:
            break;
        }

        fwrite(out_buffer, sizeof(unsigned char), size, fOut); //write back to the output image

        fclose(fIn);
        fclose(fOut);

        cout << endl<< endl;
        improcess();
    }
        break;
    case 5 :{
        FILE *fp = fopen("barbara.bmp", "rb"); //read the file//

        unsigned char *imageData;       // to store the image information
        unsigned char *newimageData;    // to store the new image information, i.e. the negative image
        unsigned char imageHeader[54];  // to get the image header
        unsigned char colorTable[1024]; // to get the colortable

        int i, j; // loop counter variables

        fread(imageHeader, sizeof(unsigned char), 54, fp); // read the 54-byte from fp to imageHeader

        // extract image height and width from imageHeader
        int width = *(int *)&imageHeader[18];
        int height = *(int *)&imageHeader[22];
        int bitDepth = *(int *)&imageHeader[28];

        int imgDataSize = width * height; // calculate image size

        imageData = (unsigned char *)malloc(imgDataSize * sizeof(unsigned char)); // allocate the block of memory as big as the image size
        newimageData = (unsigned char *)malloc(imgDataSize * sizeof(unsigned char));

        if (bitDepth <= 8)                                      // COLOR TABLE Present
            fread(colorTable, sizeof(unsigned char), 1024, fp); // read the 1024-byte from fp to colorTable

        fread(imageData, sizeof(unsigned char), imgDataSize, fp);

        //Calculate the mean of the image
        for (i = 0; i < height; i++)
        {
            for (j = 0; j < width; j++)
            {
                newimageData[i * width + j] = 255 - imageData[i * width + j];
            }
        }

        FILE *fo = fopen("images/barbara_gray-negative.bmp", "wb");

        fwrite(imageHeader, sizeof(unsigned char), 54, fo); // write the header back.

        if (bitDepth <= 8)                                       // COLOR TABLE Present
            fwrite(colorTable, sizeof(unsigned char), 1024, fo); // write the color table back

        fwrite(newimageData, sizeof(unsigned char), imgDataSize, fo); // write the values of the negative image.

        fclose(fo);
        fclose(fp);
        cout<<endl;
        improcess();
    }
        break;
    default:
        setColor(12);
        cout<<"NOT ABLE TO PROCESS THE IMAGE"<<endl;
        cout<<"ENTER A VALID CHOICE";
        _getch();
        goto hell1;
        break;

    }}
    else{
        my_exit();
    }
    setColor(10);
    cout<<"\n\nDo you want to apply any other Operation on the image(Press y/n)"<<endl;
    cin>>press;
    if(press=='y'||press=='Y')
        goto hell;
        else
            my_exit();
    return 0;
 }
