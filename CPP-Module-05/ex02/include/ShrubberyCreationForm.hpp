
#ifndef	SHRUBBERY_H
#define	SHRUBBERY_H

#include "AForm.hpp"
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

class Shrubbery : public AForm
{
	public:
		Shrubbery(const std::string &target);
		Shrubbery(const Shrubbery &other);
		Shrubbery &operator=(const Shrubbery &other);
		~Shrubbery(void);

		virtual void	execute(void) const;
	
	private:
		std::string	_target;
};

#endif