kill -9 $(ps | grep "./Nibbler" | cut -d " " -f$1)