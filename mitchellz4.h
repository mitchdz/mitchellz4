enum _mlz4_config_error
{
    E_MLZ4_SUCCESS = 0,
    E_MLZ4_INVALID_INPUT = 1,
    E_MLZ4_FILE_NOT_FOUND = 2
};

typedef enum _mlz4_config_error mlz4_error_t;

struct _errordesc {
    int code;
    char *message;
} mlz4_errordesc[] = {
    { E_MLZ4_SUCCESS, "No error" },
    { E_MLZ4_INVALID_INPUT, "Invalid input" },
    { E_MLZ4_FILE_NOT_FOUND, "File not found" }
};

mlz4_error_t mitchellz4Compress(char *inputFile, char*outputFile);
