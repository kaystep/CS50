#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    //todo
    //Open memeory card file
    //find beginning of JPEG
    //Open a new JPEG
    //Write 512 bytes until new JPEG is found
    //Detect the end of the file
    
    //Pointer to the file with all of the corrupted jpegs
    FILE * infile;
    infile = fopen("card.raw", "r");
    int JPEG_counter = 0;
    unsigned char buffer[512];
    char JPEG_Name[8];
    FILE* outfile = NULL;
    
    if (infile == NULL)
    {
        fprintf(stderr, "Could not open %s.\n","card.raw");
        return 1;
    }
    
    
   
    
    
    
while(fread(buffer, 512, 1, infile))
{
        //Check to see if the first 4 bytes are the beginning of a new JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
    {
        //close any open files
        if (outfile != NULL)
        {
            fclose(outfile);
        }
        
        //Create JPEG Naming system
        sprintf(JPEG_Name, "%03d.jpg", JPEG_counter);
        //Open new JPEG file
        outfile = fopen(JPEG_Name, "w");
        //Write 512 bytes until the new JPEG is found
        fwrite(buffer, 512, 1, outfile);
        
        JPEG_counter ++;
    }
    else
    {
        //Keep writing those bytes until we get to the start of a new JPEG
        if(NULL != outfile)
        fwrite(buffer, 512, 1, outfile);
    }
}
    if (outfile != NULL)
    fclose(outfile);
    
    fclose(infile);
    
    return 0;
}