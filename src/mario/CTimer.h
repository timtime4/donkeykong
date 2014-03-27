/*
	Timer.h
*/

class Timer{		// Timer class

        public:
        
                Timer();                // Constructor
                void start();           // Various clock actions
                void stop();
                void pause();
                void unpause();

                int get_ticks();        // Gets the time of the timer
                bool is_started();      // Checks the status of the timer
                bool is_paused();

	private:

		int startTicks; 	// The clock time when the timer started
		int pausedTicks;	// The ticks stored when the timer was paused
		bool paused;		// The timer status
		bool started;

};
