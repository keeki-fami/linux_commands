#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
	
	//error:argc is too small.
	if(argc<2){
		fprintf(stderr,"Usage:%s {file...}\n",argv[0]);
		return EXIT_FAILURE;
	}

	for(int i=1;i<argc;i++){
		FILE *fp = fopen(argv[i],"r");
		
		//error:fp is null
		if(fp==NULL){
			perror("fopen");
			return EXIT_FAILURE;
		}

		int buf;

		while(1){
			buf = fgetc(fp);
			if(buf<0){
				//end of file or not
				if(feof(fp)!=0){
					break;
				}else{
					perror("fgetc");
					fclose(fp);
					return EXIT_FAILURE;
				}
			}
			
			if(putchar(buf)<0){
				perror("putchar");
				fclose(fp);
				return EXIT_FAILURE;
			}
		}
		fclose(fp);
	}

	return EXIT_SUCCESS;

}
