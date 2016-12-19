#include "LoopMatcher.hpp"


using namespace clang::ast_matchers;

StatementMatcher LoopMatcher =
  forStmt(hasLoopInit(declStmt(hasSingleDecl(varDecl(
	hasInitializer(integerLiteral(equals(0)))))))).bind("forLoop");


void LoopPrinter::run(const MatchFinder::MatchResult &result)
{
	const clang::ForStmt *fs = result.Nodes.getNodeAs<clang::ForStmt>("forLoop");
	if (nullptr != fs)
	{
		fs->dump();
	}
}
