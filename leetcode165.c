int compareVersion(char* version1, char* version2) {
	int v1=0,v2=0;
	char *old_version1=NULL, *old_version2=NULL;
	char *context1=NULL, *context2=NULL;

	while(1) {
		old_version1=strtok_r(version1,".",&context1);
		(old_version1!=NULL)?(v1=atoi(old_version1)):(v1=0);

		old_version2=strtok_r(version2,".",&context2);
		(old_version2!=NULL)?(v2=atoi(old_version2)):(v2=0);

		if(v1==v2) 
		{
			if(old_version1==NULL)
			{
				if(old_version2==NULL)
				{
					return 0;
				}
			}
		}
		
		version1=version2=NULL;

		if(v1!=v2) {
			return (v1>v2)?(1):(-1);
		}
	}
}
