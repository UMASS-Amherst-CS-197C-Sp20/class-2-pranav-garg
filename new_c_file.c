FILE *fp;
fp = fopen("test.txt", "w+");
fprintf(fp, "this is testing for fprintf...\n");
fputs("This is testing for fputs...\n", fp);
fclose(fp); 
