
#include <cstdlib>

#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <sstream>
//include <vector>

std::regex LINE_PTT{R"((\d*)\|(\d*)\|(\d*)\|(.*))"};
std::smatch PIECES_MATCH;

void
parse_txt(const std::string& txt, long (&vid)[3], std::string& cnt){
	if(regex_match(txt, PIECES_MATCH, LINE_PTT)){
		//fprintf(stdout, "MATCHES\n");
		for(long aa = 0; aa < (long)PIECES_MATCH.size(); aa++){
			std::ssub_match sub_match = PIECES_MATCH[aa];
			std::string piece = sub_match.str();
			if((aa >= 1) && (aa <= 3)){
				vid[aa-1] = atol(piece.c_str());
			}
			if(aa == 4){
				cnt = piece;
			}
			//fprintf(stdout, "+%ld:'%s'\n", aa, piece.c_str()); // dbg_prt
		}
	}
	
}
	
int 
main(int argc, char *argv[]) 
{ 
	if(argc < 3){
		fprintf(stdout, "%s <full_verses_file> <bib_file>\n", argv[0]);
		return -1;
	}
    std::string fn1 = argv[1];
    std::string fn2 = argv[2];
	
    std::ifstream ff1(fn1.c_str());
    std::string txt1 = fn1.c_str(); 
	
    std::ifstream ff2(fn2.c_str());
    std::string txt2 = fn2.c_str(); 
	
	std::smatch pieces_match;
	
	long vid1[3] = {-1, -1, -1};
	long vid2[3] = {-1, -1, -1};

    std::string cnt1 = ""; 
    std::string cnt2 = ""; 

	std::stringstream full_verse;
	std::string verse_str = "";
	
    while (std::getline(ff1, txt1)){
		
		//fprintf(stdout, "-----------------\n");
		//fprintf(stdout, "'%s'\n", txt1.c_str());
		
		parse_txt(txt1, vid1, cnt1);
		//fprintf(stdout, "PARSED.%ld,%ld,%ld=%s\n", vid1[0], vid1[1], vid1[2], cnt1.c_str()); // dbg_prt
		
		while (std::getline(ff2, txt2)){
			parse_txt(txt2, vid2, cnt2);
			if((vid2[0] == vid1[0]) && (vid2[1] == vid1[1]) && (vid2[2] == vid1[2])){
				fprintf(stdout, "%s\n", txt2.c_str());
				break;
			}
		}
    }
    
}

