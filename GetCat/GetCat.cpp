#include <fstream>
#include <fmt/format.h>


#define CPPHTTPLIB_OPENSSL_SUPPORT
#include <httplib.h>



int main()
{
    int cantsCount = 0;
    printf("CAT DOWNLOADER 3000\n");
    printf("Enter cat count: ");
    std::cin >> cantsCount;
    printf("Working...\n");
    auto cli = httplib::Client("https://thiscatdoesnotexist.com");
   
    for (int i = 0; i < cantsCount; ++i)
    {
        auto str = cli.Get("/").value().body;
        std::cout << fmt::format("[{}] Downloaded >> {} bytes\n",i+1, str.size());

        std::ofstream(fmt::format("cat_{}.jpg", i+1), std::ios::binary).write(str.c_str(), str.size());

    }
    printf("Done\n");
    std::cin.get();
}