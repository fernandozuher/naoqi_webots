ifeq ($(WEBOTS_HOME),)
$(error WEBOTS_HOME environment variable is not set, please set it before running this Makefile)
endif

default clean:
	@+echo "# aldebaran simulator-sdk"
	@+make --silent -C aldebaran $(MAKECMDGOALS)
	@+echo "# naoqi_webots controller"
	@+make --silent -C controllers/naoqi_webots $(MAKECMDGOALS)
