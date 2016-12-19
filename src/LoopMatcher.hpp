#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

extern clang::ast_matchers::StatementMatcher LoopMatcher;

class LoopPrinter : public clang::ast_matchers::MatchFinder::MatchCallback
{
public :
	virtual void run(const clang::ast_matchers::MatchFinder::MatchResult &result);

};
