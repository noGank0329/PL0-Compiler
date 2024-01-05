#include "codegen.h"
#include "parser.h"
#include "cxxopts.hpp"
#include <iostream>

using namespace cxxopts;

static std::string input_file_path;
static std::string output_file_path;
static bool use_antlr;

/// @brief parse command line option and init some global variable
/// @param argc
/// @param argv
/// @return
int parseCmdArgs(int argc, char *argv[])
{

    try
    {
        std::unique_ptr<cxxopts::Options> allocated(new cxxopts::Options(argv[0], "compiler"));
        auto &options = *allocated;
        options
            .positional_help("[optional args]")
            .show_positional_help();

        options
            .set_width(70)
            .set_tab_expansion()
            .add_options()("i, input", "The sources input file", cxxopts::value<std::string>())("o, output", "Output file name", cxxopts::value<std::string>()->default_value("a.out"))("use-antlr", "Use antlr parse", cxxopts::value<bool>()->default_value("false"))("h, help", "Print help");

        auto result = options.parse(argc, argv);

        if (result.count("help"))
        {
            std::cout << options.help({""}) << std::endl;
            exit(0);
        }

        if (!result.count("input"))
        {
            std::cerr << "No input files was given!" << std::endl;
            return 1;
        }

        input_file_path = result["input"].as<std::string>();
        output_file_path = result["output"].as<std::string>();
        use_antlr = result["use-antlr"].as<bool>();
        return 0;
    }
    catch (const cxxopts::exceptions::exception &e)
    {
        std::cout << "Error parsing options: " << e.what() << std::endl;
        return 1;
    }
}

int main(int argc, char *argv[])
{
    /// parse command line option

    std::cout << "1. Begin to parse cmd line option..." << std::endl;

    if (parseCmdArgs(argc, argv))
    {
        std::cerr << "Exit with error!" << std::endl;
        return 1;
    }

    std::cout << "success parse cmd line option!" << std::endl;

    std::cout << "2. Begin to parse and get ast..." << std::endl;
    Parser *parser = nullptr;

    if (use_antlr)
    {
        parser = new AntlrAstParser();
    }
    else
    {
        parser = new CommonAstParser();
    }

    /// 解析源代码生成AST
    Program *prog = parser->parse(input_file_path.c_str());

    if (!prog)
    {
        std::cerr << "Can not parse ast!" << std::endl;
        return 1;
    }

    std::cout << "success generate ast!" << std::endl;

    std::cout << "3. Begin to write tac code to file..." << std::endl;

    /// 生成三地址码
    CodeGen codegen;
    auto tac_prog = codegen.codegen(prog);
    tac_prog->dumpInstToFile(output_file_path.c_str());

    std::cout << "success to write tac file to " << output_file_path << "!" << std::endl;

    return 0;
}