#include <iostream>
#include <cctype>
#include <algorithm>
#include <cstring>

#include <qemuvirt_install.h>
 
bool base_installed = false;
bool aur_installed = false;
bool virt_installed = false;

char pacman[50] = "sudo pacman ";
char gitclone[50] = "git clone ";
char yay[50] = "yay -S ";
std::string base_packages[] = {"git", "reflector"};
std::string app_packages[] = {"firefox", "discord", "neofetch", "code"};
std::string aur_packages[] = {"downgrade"};
static void install_base() {
    for (int i = 0; i < sizeof(base_packages); ++i) {
        
    }
}
static void install_app() {

}
static void install_aur() {
    std::cout << "Making AUR temporary folder..." << std::endl;
    system("cd Desktop/ && mkdir __AUR_temp");
    std::cout << "Checking for git..." << std::endl;
   
    int git_pack = system("git");
    if (git_pack != 0) {
        std::cout << "git is not installed, installing..." << std::endl;
        system(strcat(pacman, "-S git"));
    }
    system("cd Desktop/__AUR_temp && git clone https://aur.archlinux.org/yay.git");
    system("cd Desktop/__AUR_temp/yay && makepkg -si");
}
static void help_list() {
    std::cout << "Installer terminal for Arch Linux works like archinstall but with my packages and configurations." << std::endl;
    std::cout << " 0 - Close" << std::endl;
    std::cout << " 1 - Install AUR/yay" << std::endl;
}
int main() {
    bool closing = false;
    #ifdef __linux__
        system("clear");
        help_list();

        do {
            char input[1];
            std::cout << "> ";
            std::cin >> input;
            if (input == "h") {
                help_list();
                return;
            }
            if (input == "0") {
                closing = true;
                return;
            }
            if (input == "1") {
                
                return;
            }
        } while (!closing);
    #endif
    std::cout << "Exiting..." << std::endl;
    return 0;
}