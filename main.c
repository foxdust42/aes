#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static int verbose_flag = 0;

int main(int argc, char ** argv){
    //handling options
    //from : https://www.gnu.org/software/libc/manual/html_node/Getopt-Long-Options.html
    int c;
    // opterr = 0; // disables getopt warning messages for improper '?' or incomplete options
    while (1){
        static struct option long_options[]={
            {"help", optional_argument, 0, 'h'},
            {"verbose", no_argument, &verbose_flag, 1},
            {"in", required_argument, 0, 'i'},
            {"out", required_argument, 0 , 'o'},
            {"key-file", required_argument, 0, 'k'},
            {"gen-key", no_argument, 0, 'g'},
            {"bits", required_argument, 0, 'b'}
        };
        int option_index = 0;

        c = getopt_long(argc, argv, "h::i:o:k:gb:", long_options, &option_index);

        if (c == -1){
            break;
        }

        switch (c)
        {
        case 0:
            if(long_options[option_index].flag != 0){
                break;
            }
            printf("option %s", long_options[option_index].name);
            if (optarg)
            {
                printf(" with arg %s", optarg);
            }
            printf("\n");    
            break;
        
        case 'h':
            printf("No help yet"); //TODO: helpmsg
            if(optarg){
                printf("w/ arg %s", optarg);
            }
            printf("\n");
            break;
        case 'i':
        case 'o':
        case 'k':
        case 'g':
        case 'b':
            printf("option %s not implemented yet", long_options[option_index].name);
            if (optarg)
            {
                printf(" w/ arg %s", optarg);
            }
            printf("\n");
            break;
            
        case '?':
            //printf("Invalid\n");
            break;
        default:
            //proper boned innit
            abort();
            break;
        }
    }

    if (optind < argc){
        printf("non option args: \n");
        while (optind < argc)
        {
            printf("%s\n", argv[optind++]);
        }
    }

    fprintf(stdout, "All is done\n");
    return 0;
}