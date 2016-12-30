
int num=0;

char* moveStr(char* s){
	while( (*s != '\0') && (*s != '.') )
	{
		s++;
	}

	if(*s == '\0')
	{
		return NULL;
	}
	else
	{
		s++;
		return s;
	}
}


char* nextNumToGlobalNum(char* s)
{
    if(s==NULL)
    {
        return NULL;
    }
    
	s=moveStr(s);
	if(s==NULL)
	{
		num=0;
		return NULL;
	}
	else
	{
		num=atoi(s);
		return s;
	}

}



int compareVersion(char* version1, char* version2) {
	/*int v1Len=strlen(version1);
	int v2Len=strlen(version2);*/
	int v1=0;
	int v2=0;

	v1=atoi(version1);
	v2=atoi(version2);
	if(v1!=v2) 
	{
		return (v1>v2)?(1):(-1);
	}

	while(1)
	{
	    num=0;
	    version1=nextNumToGlobalNum(version1); v1=num;
		
		num=0;
		version2=nextNumToGlobalNum(version2); v2=num;
		
		if(v1==v2 && nextNumToGlobalNum(version1)==NULL && nextNumToGlobalNum(version2)==NULL)
		{
			return 0;
		}
		
		if(v1!=v2)
		{
			return (v1>v2)?(1):(-1);
		}

	}
}
