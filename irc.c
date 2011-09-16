#include<u.h>
#include<libc.h>

#define TERM_NLINE "\r\n"
/*check it in git
*/
void
main(void)
{
	int fd;
	char* buf[1024*1024];
	int n;
	
	/*
		connect to the server irc.freenode.net on the port 6667
	*/
	
	fd = dial("tcp!irc.freenode.net!6667", nil, nil, nil);
	if(fd < 0)
		sysfatal("dial: %r");
	
	/*
	 send your info to the server
	*/	
	
	fprint(fd, "PASS asdf\r\n");
	fprint(fd, "USER a b c :d\r\n");
	fprint(fd, "NICK aibrahim\r\n");
	fprint(fd, "PRIVMSG visof :Hello visof.\r\n");
	
	/*
		get the info the server send to you
	*/
	
	while(n = read(fd, buf, sizeof buf) > 0)
		print("%s", buf);
	 
	exits(nil);	
}
