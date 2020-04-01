#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp;
  int j,i,ch;
  int offset = 0;
  int s = 0;
  char pp[20];
  pp[19] = '\0';
  int jump = 0;
  int cur_sec = 0;
  int size = 0;
  int sector_num;

  if((fp = fopen("/dev/sda","rb")) == NULL)
  {
    printf("File Open Error!");
    exit(1);
  }

  fseek(fp, 0, SEEK_END);
  size = ftell(fp);

  sector_num = (size/512) - 1;

  fseek(fp, 0, SEEK_SET);

  printf("섹터 위치(0~%d) : ", sector_num);
  scanf("%d", &cur_sec);

  for(int k = 0 ; k < cur_sec ; k++)
  {
    offset += 512;
  }
  fseek(fp, offset, SEEK_SET);

  printf("offset(h)  ");

  for(s = 0 ; s < 16 ; s++)
  {
    printf("%02X ", s);
  }printf("\n\n");

  for(i = 0 ; i < 32 ; i++)
  {
    printf("%08X  ", offset);
    offset += 16;
    for(j = 0 ; j < 16 ; j++)
    {
      if((ch = fgetc(fp)) != EOF)
      {
        printf(" %02X", ch);
        if(int(ch) <=15 || int(ch) >= 127)
        {
          pp[j] = '.';
        }
        else
        {
          pp[j] = char(ch);
        }
      }
    }
    printf("  %s\n", pp);
  }
  printf("\n\n");

  fclose(fp);

  return 0;
}
