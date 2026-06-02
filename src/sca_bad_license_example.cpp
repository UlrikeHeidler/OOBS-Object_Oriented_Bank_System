#include 
#include <idna.h>
#include <stringprep.h>
int main() {
const char* input = "müller.de";
char* output = nullptr;
int rc = idna_to_ascii_8z(input, &output, IDNA_USE_STD3_ASCII_RULES);
if (rc == IDNA_SUCCESS && output) {
    std::cout << "Punycode: " << output << std::endl;
    free(output);
} else {
    std::cerr << "IDNA error: " << idna_strerror(rc) << std::endl;
}

const char* ver = stringprep_check_version(nullptr);
if (ver) {
    std::cout << "libidn version detected: " << ver << std::endl;
}
return 0;

}
