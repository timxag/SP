/* $e20 */
#include "code-gen.h"
using namespace std;
int tCG::p01(){ // S -> PROG
  string header ="/*  " + lex.Authentication()+"   */\n";
  header += "#include \"mlisp.h\"\n";
  header += declarations;
  header += "//________________ \n";
  S1->obj = header + S1->obj;
	return 0;}
int tCG::p02(){ //   PROG -> CALCS1
	S1->obj = "int main() {\n" + S1->obj
    + "    std::cin.get();\n    return 0;\n}\n";
	return 0;}
int tCG::p03(){ //   PROG -> DEFS
	S1->obj += "int main(void) {\n"
    "display(\"No calculations!\");newline();\n"
    "std::cin.get();\nreturn 0;\n}\n";
	return 0;}
int tCG::p04(){ //   PROG -> DEFS CALCS1
	S1->obj += "int main(void) {\n" + S2->obj + "    std::cin.get();\n return 0;\n}\n";
	return 0;}
int tCG::p05(){ // CALCS1 -> CALCS
	return 0;}
int tCG::p06(){ //  CALCS -> CALC
	return 0;}
int tCG::p07(){ //  CALCS -> CALCS CALC
	S1->obj += S2->obj;
    ++S1->count;return 0;}
int tCG::p08(){ //   CALC -> E1
	S1->obj = "display("+S1->obj+"); newline();\n";
    return 0;}
int tCG::p09(){ //   CALC -> BOOL
	S1->obj = "display("+S1->obj+"); newline();\n";
    return 0;}
int tCG::p10(){ //   CALC -> STR
	 S1->obj = "display("+S1->obj+"); newline();\n";
    return 0;}
int tCG::p11(){ //   CALC -> DISPSET
	S1->obj += ";\n";
    return 0;}
int tCG::p12(){ //     E1 -> E
	return 0;}
int tCG::p13(){ //      E -> $id
	 S1->obj = decor(S1->name);
    return 0;}
int tCG::p14(){ //      E -> $zero
	S1->obj = S1->name;
    return 0;}
int tCG::p15(){ //      E -> ADD
	S1->obj = "( " + S1->obj + ")";
	return 0;}
int tCG::p16(){ //      E -> SUB
	S1->obj = "( " + S1->obj + ")";
	return 0;}
int tCG::p17(){ //      E -> DIV
	return 0;}
int tCG::p18(){ //      E -> MUL
	S1->obj = "( " + S1->obj + ")" ;
	return 0;}
int tCG::p19(){ //      E -> IF
	return 0;}
int tCG::p20(){ //      E -> CPROC
	return 0;}
int tCG::p21(){ //    ADD -> HADD E1 )
	S1->obj += S2->obj;
    S1->obj += ")";
    return 0;}
int tCG::p22(){ //   HADD -> ( +
	S1->obj = "(";
    return 0;}
int tCG::p23(){ //   HADD -> HADD E1
	S1->obj += S2->obj + " + ";
    ++S1->count;
    return 0;}
int tCG::p24(){ //    SUB -> HSUB E1 )
	if (S1->count == 1) {
			S1->obj += "-" + S2->obj + ")";
		} else {
			S1->obj += S2->obj + ")";
		}

    return 0;}
int tCG::p25(){ //   HSUB -> ( - E
	S1->count = 0;
	S1->obj = "(" + S3->obj + " - ";
	return 0;}
int tCG::p26(){ //    DIV -> HDIV E1 )
	if (S1->count == 1){
		S1->obj += "1 / " + S2->obj;
	} else
		S1->obj += S2->obj;
	return 0;}
int tCG::p27(){ //   HDIV -> ( / E
	S1->obj = S3->obj + "/";
	return 0;}
int tCG::p28(){ //    MUL -> HMUL E1 )
	S1->obj += S2->obj + ")";
	return 0;}
int tCG::p29(){ //   HMUL -> ( *
	S1->obj = "(";
	return 0;}
int tCG::p30(){ //   HMUL -> HMUL E1
	S1->obj += S2->obj + " * ";
	return 0;}
int tCG::p31(){ //     IF -> IFTRUE E1 )
	S1->obj += ":" + S2->obj;
	return 0;}
int tCG::p32(){ // IFTRUE -> HIF E
	S1->obj += S2->obj ;
	return 0;}
int tCG::p33(){ //    HIF -> ( if BOOL
	S1->obj = "" + S3->obj + " ?";
	return 0;}
int tCG::p34(){ //  CPROC -> HCPROC )
	S1->obj+=")";
	return 0;}
int tCG::p35(){ // HCPROC -> ( $id
	S1->obj = decor(S2->name) + "(";
	S1->count = 0;
	return 0;}
int tCG::p36(){ // HCPROC -> HCPROC E
	if (S1->count > 0)
		S1->obj += ", ";

	S1->obj += S2->obj;
  ++(S1->count);
	return 0;
}
int tCG::p37(){ //   BOOL -> $bool
	if (S1->name == "#t")
		S1->obj = "true";
	else
    S1->obj = "false";
	return 0;}
int tCG::p38(){ //   BOOL -> CPRED
	return 0;}
int tCG::p39(){ //   BOOL -> REL
	return 0;}
int tCG::p40(){ //   BOOL -> OR
	return 0;}
int tCG::p41(){ //   BOOL -> ( not BOOL )
	S1->obj = "(!" + S3->obj + ")";

	return 0;
}
int tCG::p42(){ //  CPRED -> HCPRED )
	S1->obj += ")";
    return 0;
}
int tCG::p43(){ // HCPRED -> ( $idq
	S1->obj = decor(S2->name) + "(";

    return 0;
}
int tCG::p44(){ // HCPRED -> HCPRED E
	if(S1->count) S1->obj += ", ";
	S1->obj += S2->obj;
	++(S1->count);
	return 0;}

int tCG::p45(){ //    REL -> HREL E1 )
	S1->obj += S2->obj + ")";
	return 0;
}
int tCG::p46(){ //   HREL -> ( <= E
	S1->obj = "(" + S3->obj + " <= ";
	return 0;
}
int tCG::p47(){ //   HREL -> ( = E
	S1->obj = "(" + S3->obj + " == ";
	return 0;}
int tCG::p48(){ //     OR -> HOR BOOL )
	S1->obj += S2->obj + ")";
	return 0;
}
int tCG::p49(){ //    HOR -> ( or
	S1->obj = "(";
	return 0;}
int tCG::p50(){ //    HOR -> HOR BOOL
	S1->obj += S2->obj + " || ";
	return 0;}
int tCG::p51(){ //    STR -> $str
	S1->obj = S1->name;
	return 0;
}
int tCG::p52(){ //    STR -> SIF
	return 0;}
int tCG::p53(){ //    SIF -> SIFTRUE STR )
	S1->obj += ":"+S2->obj;
	return 0;}
int tCG::p54(){ //SIFTRUE -> HIF STR
	S1->obj += S2->obj;
	return 0;}

int tCG::p55(){ //    SET -> HSET E1 )
	S1->obj += " = " + S2->obj ;
	return 0;}
int tCG::p56(){ //   HSET -> ( set! $id
	S1->obj += decor(S3->name);
	return 0;}
int tCG::p57(){ //DISPSET -> ( display E1 )
	S1->obj = "display("+S3->obj+")";
	return 0;}

int tCG::p58(){ //DISPSET -> ( display BOOL )
	S1->obj = "display("+S3->obj+")";
	return 0;}
int tCG::p59(){ //DISPSET -> ( display STR )
	S1->obj = "display("+S3->obj+")";
	return 0;}
int tCG::p60(){ //DISPSET -> ( newline )
	S1->obj = "newline()";
	return 0;}
int tCG::p61(){ //DISPSET -> SET
	return 0;}
int tCG::p62(){ //   DEFS -> DEF
	return 0;}
int tCG::p63(){ //   DEFS -> DEFS DEF
	S1->obj += S2->obj;
	return 0;
}
int tCG::p64(){ //    DEF -> PRED
	return 0;}
int tCG::p65(){ //    DEF -> PROC
	return 0;}
int tCG::p66(){ //   PRED -> HPRED BOOL )
	S1->obj += S2->obj + ";\n}\n";
  return 0;
}
int tCG::p67(){ //  HPRED -> PDPAR )
	S1->obj += ")";
    declarations += S1->obj + ";\n";
    S1->obj += "{\n  return ";
    S1->count = 0;
	return 0;}
int tCG::p68(){ //  PDPAR -> ( define ( $idq
	S1->obj = "bool " + decor(S4->name) + "(";
    S1->count = 0;
	return 0;}
int tCG::p69(){ //  PDPAR -> PDPAR $id
    if(S1->count)S1->obj += ", ";
	S1->obj += "double " + decor(S2->name);
	++(S1->count);
	return 0;}

int tCG::p70(){ //   PROC -> HPROC $dec )
	S1->obj += "return " + S2->name + ";\n}\n";
	return 0;
}
int tCG::p71(){ //   PROC -> HPROC E1 )
	S1->obj += "return " + S2->obj + ";\n}\n";
    return 0;}
int tCG::p72(){ //  HPROC -> PCPAR )
	S1->obj += ")";
    declarations += S1->obj + ";\n";
    S1->obj += " {\n";
    return 0;
}
int tCG::p73(){ //  HPROC -> HPROC DISPSET
	S1->obj += S2->obj + ";\n";
    return 0;}
int tCG::p74(){ //  PCPAR -> ( define ( $id
	S1->obj = "double " + decor(S4->name) + "(";
    S1->count = 0;
    return 0;}
int tCG::p75(){ //  PCPAR -> PCPAR $id
	if (S1->count > 0) S1->obj += ", ";

    S1->obj += "double " + decor(S2->name);
    ++S1->count;
    return 0;
}
//_____________________
int tCG::p76(){return 0;} int tCG::p77(){return 0;}
int tCG::p78(){return 0;} int tCG::p79(){return 0;}
int tCG::p80(){return 0;} int tCG::p81(){return 0;}
int tCG::p82(){return 0;} int tCG::p83(){return 0;}
int tCG::p84(){return 0;} int tCG::p85(){return 0;}
int tCG::p86(){return 0;} int tCG::p87(){return 0;}
int tCG::p88(){return 0;} int tCG::p89(){return 0;}
int tCG::p90(){return 0;} int tCG::p91(){return 0;}
int tCG::p92(){return 0;} int tCG::p93(){return 0;}
int tCG::p94(){return 0;} int tCG::p95(){return 0;}
int tCG::p96(){return 0;} int tCG::p97(){return 0;}
int tCG::p98(){return 0;} int tCG::p99(){return 0;}
int tCG::p100(){return 0;} int tCG::p101(){return 0;}
int tCG::p102(){return 0;} int tCG::p103(){return 0;}
int tCG::p104(){return 0;} int tCG::p105(){return 0;}
int tCG::p106(){return 0;} int tCG::p107(){return 0;}
int tCG::p108(){return 0;} int tCG::p109(){return 0;}
int tCG::p110(){return 0;}

