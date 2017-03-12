

#ifndef CGA_SHAPE_Y_IO_2_H
#define CGA_SHAPE_Y_IO_2_H
#include <cstdio>//..fclose(),FILE,fopen(),fseek(),ftell(),printf(),SEEK_END,...
#include <cstdlib>//......................................................exit()
#include <cstring>//................memset(),strchr(),strlen(),strstr(),strtok()
#include <vector>//.......................................................vector
namespace yIo2{
    inline char*ReadTextFile(//<=============================READ TEXT FROM A FILE
            const char*f){//<----------------------------------THE NAME OF A TEXT FILE
        FILE*F=fopen(f,"rb");/*->*/if(!F)printf("\nCan't find \"%s\".\n",f),exit(1);
        unsigned n;/*<-*/fseek(F,0,SEEK_END),n=ftell(F),rewind(F);
        char*s=new char[n+1];/*<-*/fread(s,1,n,F),fclose(F),s[n]=0;
        return s;//.....................note that s points to newly allocated memory
    }
    inline unsigned WriteTextFile(//<=========================WRITE TEXT TO A FILE
            const char*f,//<---------------------------------THE NAME OF THE TEXT FILE
            const char*s,//<------------------------------------THE TEXT TO BE WRITTEN
            const char*m="wb"){//<---------------USE "wb" TO OVERWRITE, "ab" TO APPEND
        FILE*F=fopen(f,m);/*->*/if(!F)printf("\nCan't open \"%s\".\n",f),exit(1);
        unsigned n=fwrite(s,1,strlen(s),F);/*&*/fclose(F);
        return n;//.........................number of characters written to the file
    }
    inline char*RemoveLineComments(//<=====================OVERWRITE LINE COMMENTS
            char*s,//<---------------------------TEXT THAT MIGHT CONTAIN LINE COMMENTS
            const char*c="#",//<------------------------BEGINNING-OF-COMMENT INDICATOR
            char r=' '){//<------THE CHARACTER THAT WILL BE USED TO OVERWRITE COMMENTS
        for(char*t=s;t=strstr(t,c);memset(t,r,strcspn(t,"\n\f\r")));
        return s;
    }
    inline char*RemoveBlockComments(//<===================OVERWRITE BLOCK COMMENTS
            char*s,//<--------------------------TEXT THAT MIGHT CONTAIN BLOCK COMMENTS
            const char*c="/*",//<-----------------------BEGINNING-OF-COMMENT INDICATOR
            const char*e="*/",//<-----------------------------END-OF-COMMENT INDICATOR
            char r=' '){//<------THE CHARACTER THAT WILL BE USED TO OVERWRITE COMMENTS
        int m=strlen(c),n=strlen(e);
        for(char*t=s,*u;t=strstr(t,c);memset(t,r,u-t+n))if(!(u=strstr(t+m,e)))break;
        return s;//.........block comments without end indicators aren't overwritten
    }
    inline std::vector<char*>Parse(//<===================================1D PARSER
            char*s,//<----------------------------------------TEXT THAT WILL BE PARSED
            const char*d=" ,\t\n\f\r"){//<----------------------------------DELIMITERS
        std::vector<char*>V;/*<-*/for(s=strtok(s,d);s;s=strtok(0,d))V.push_back(s);
        return V;
    }
    inline std::vector<std::vector<char*> >Parse2D(//<=2D PARSER (CALLS 1D PARSER)
            char*s,//<----------------------------------------TEXT THAT WILL BE PARSED
            const char*d=" ,\t",//<------------------------TOKEN-DELIMITING CHARACTERS
            const char*e="\n\f\r"){//<-----------------------ROW-DELIMITING CHARACTERS
        std::vector<std::vector<char*> >V;
        char*b,*c=new char[strlen(d)+strlen(e)+1];
        for(strcat(strcpy(c,d),e);*(b=s+strspn(s,c));V.push_back(Parse(b,d)))
            s=b+strcspn(b,e),!*s?s:(*s=0,++s);
        delete[]c;
        return V;//.........the number of columns per row may differ from row to row
    }
    inline char*PreParse(//<=======SELECTIVELY REPLACE DELIMITERS WITH A CHARACTER
            char*s,//<-----------------------------------------------A CHARACTER ARRAY
            const char*b="\"",//<--------------BEGINNING OF IGNORED-DELIMITERS SECTION
            const char*e="\"",//<--------------------END OF IGNORED-DELIMITERS SECTION
            const char*d=" ,\t\n\f\r",//<------------------------DELIMITING CHARACTERS
            char r='#'){//<--------------------------------------REPLACEMENT CHARACTER
        const char*u;
        for(char*t=s,c=0;*t;++t){
            if(strchr(d,*t)&&!c)*t=r;
            else if(strchr(b,*t))u=b,b=e,e=u,c&1?++c:--c;
            else if(strchr(e,*t))u=b,b=e,e=u,c&1?--c:++c;}
        return s;
    }
}
#endif //CGA_SHAPE_Y_IO_2_H
