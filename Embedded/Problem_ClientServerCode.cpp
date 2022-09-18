Consider the sample pseudocode of a client in a typical Client Server Pattern of communication between two tasks in an RTOS. Identify various issues in the pseudocode and suggest ways to fix them. Task/Thread-A is the client and Task/Thread-B is the server.



Thread A:

INIT_THREADA_DATA()

DO Forever

	WAIT_FOR_MSG

	CASE MSGID

		MSG1:

			Process MSG1

			Send Request to THREAD B

			WAIT FOR RESPONSE from THREAD B

			Process the RESPONSE

			Break;

		MSG2:

			Process Msg2;

			Break;

		INVALID_MSG:

	END CASE

END DO

