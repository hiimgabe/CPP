
#ifndef	SHRUBBERY_H
#define	SHRUBBERY_H

#include "AForm.hpp"
#include <fstream>

#define TREE "       ,.,\n" \
"      MMMM_    ,..,\n" \
"        \"_ \"__\"MMMMM          ,...,,\n" \
" ,..., __.\" --\"    ,.,     _-\"MMMMMMM\n" \
"MMMMMM\"___ \"_._   MMM\"_..\" _ \"\"\"\"\"\"\n" \
" \"\"\"\"\"    \"\" , \\_.   \"_. .\"\n" \
"        ,., _\"__ \\__./ .\"\n" \
"       MMMMM_\"  \"_    ./\n" \
"        ''''      (    )\n" \
" ._______________.-'____\"---._.\n" \
"  \\                          /\n" \
"   \\________________________/\n" \
"   (_)                    (_)\n"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm(void);

		void	execute(void) const;
	
	private:
		std::string	_target;
};

#endif